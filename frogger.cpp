#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

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

int main() {

    int magic;
    int squares;
    int start;
    int movesTaken = 0;
    int index;
    bool playing = true;

    cin >> squares;
    cin >> start;
    cin >> magic;

    index = start - 1;

    vector<int> board;

    for(int i = 0; i < squares; i++){
        int temp;
        cin >> temp;
        board.push_back(temp);
    }

    vector<int> visited;

    while(playing){
        if(board[index] == magic){
            cout << "magic" << endl;
            playing = false;
            continue;
        }
        if(bSearch(visited,index,0,visited.size() - 1) != -1){
            cout << "cycle" << endl;
            playing = false;
            continue;
        }
        visited.push_back(index);
        index += board[index];
        movesTaken ++;
        if(index < 0){
            cout << "left" << endl;
            playing = false;
            continue;
        }
        if(index >= board.size()){
            cout << "right" << endl;
            playing = false;
            continue;
        }
        sort(visited.begin(), visited.end(), myobject);
    }

    cout << movesTaken << endl;

    return 0;
}