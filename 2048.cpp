#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
typedef vector<vector<int>> vvi;

int bSearch(vector<int> search_array, int target, int left, int right){

    if(left > right){
        return -1;
    }

    int mid = floor(left + (right-left)/2);

    if(search_array[mid] == target){
        return mid;
    }else if(search_array[mid] > target){
        //go left
        return bSearch(search_array, target, left, mid - 1);
    }else{
        //go right
        return bSearch(search_array, target, mid + 1, right);
    }
}

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

vvi transpose(vvi initial){
    vector<int> temp(4,0);
    vvi newvector(4,temp);
    for(int row = 0; row < 4; row++){
        for(int column = 0; column < 4; column ++){
            newvector[column][row] = initial[row][column];
        }
    }
    return newvector;
}

vvi left(vvi initial){
    vector<int> beenmerged;
    for(int row = 0; row < 4; row++){
        int counter = 0;
        while(counter < 4){
            counter++;
            for(int column = 1; column < 4; column++){
                int current = initial[row][column];
                if(current == 0){
                    continue;
                }
                if(initial[row][column-1] == current && bSearch(beenmerged, column-1, 0, beenmerged.size()-1) == -1 && bSearch(beenmerged, column, 0, beenmerged.size()-1) == -1){
                    //merge
                    initial[row][column-1] = current*2;
                    initial[row][column] = 0;
                    beenmerged.push_back(column-1);
                    sort (beenmerged.begin(), beenmerged.end(), myobject);
                    continue;
                }
                if(initial[row][column-1] == 0){
                    initial[row][column-1] = current;
                    initial[row][column] = 0;
                }
            }
        }
        beenmerged = {};
    }
    return initial;
}

vvi right(vvi initial){
    //todo, reverse all children, not parent
    for(int i = 0; i < 4; i++){
        std::reverse(initial[i].begin(),initial[i].end());
    }
    vvi newvc = left(initial);
    for(int i = 0; i < 4; i++){
        std::reverse(newvc[i].begin(),newvc[i].end());
    }
    return newvc;
}

vvi up(vvi initial){
    vvi transposed = transpose(initial);
    return transpose(left(transposed));
}

vvi down(vvi initial){
    vvi transposed = transpose(initial);
    return transpose(right(transposed));
}

int main(){
    //0123 - left, up, right, down
    vector<int> temp(4,0);
    vvi matrix(4,temp);
    int move;
    for(int i = 0; i < 4; i++){
        for(int x = 0; x < 4; x++){
            cin >> matrix[i][x];
        }
    }
    cin >> move;

    vvi newmatrix;
    if(move == 0){
        newmatrix = left(matrix); 
    }
    else if(move == 1){
        newmatrix = up(matrix); 
    }
    else if(move == 2){
        newmatrix = right(matrix); 
    }
    else{
        newmatrix = down(matrix); 
    }

    for(int row = 0; row < 4; row++){
        for(int column = 0; column < 4; column ++){
            std::cout << newmatrix[row][column] << " ";
        }
        std::cout << endl;
    }
    return 0;
}