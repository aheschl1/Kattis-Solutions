#include<iostream>
#include<vector>
#include<map>

using namespace std;
typedef vector<vector<char>> vvc;

void solve(vvc &lot){
    map<unsigned short, unsigned int> results;
    results[0] = 0;
    results[1] = 0;
    results[2] = 0;
    results[3] = 0;
    results[4] = 0;
    for(int row = 0; row < lot.size()-1; row ++){
        for(int column = 0; column < lot[0].size() - 1; column ++){
            char a = lot[row][column], b = lot[row][column+1], c = lot[row+1][column], d = lot[row+1][column+1];
            if(a == '#' || b == '#' || c == '#' || d == '#'){
                continue;
            }
            unsigned int crushed = 0;
            crushed += (a == 'X');
            crushed += (b == 'X');
            crushed += (c == 'X');
            crushed += (d == 'X');
            results[crushed] ++;
        }
    }

    for(pair<unsigned short, unsigned int> pair : results){
        cout << pair.second << endl;
    }
}

int main(){
    unsigned int row,column;
    cin >> row >> column;
    vvc lot;
    for(int r = 0; r < row; r++){
        lot.push_back({});
        for(int c = 0; c < column; c++){
            char temp;
            cin >> temp;
            lot[r].push_back(temp);
        }
    }

    vvc &ref = lot;
    solve(ref);

    return 0;
}