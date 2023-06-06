#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<string>
#include<deque>
#include<unordered_set>
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
typedef vector<vector<pair<int, bool>>> vvpi;
typedef vector<pair<int, bool>> vpi;

void flood(vvpi &field, int r, int c, int target){
    pair<int, bool> &block = field[r][c];
    if(block.second || (block.first != target)){
        //This block is useless. SMH
        return;
    }
    block.second = true;

    if(r > 0){
        flood(field, r-1, c, target);
    }
    if(r < field.size()-1){
        flood(field, r+1, c, target);
    }
    if(c < field[0].size()-1){
        flood(field, r, c+1, target);
    }
    if(c > 0){
        flood(field, r, c-1, target);
    }
}

void calculate(vvpi &field, int r, int c){
    pair<int, bool> &block = field[r][c];
    if(block.second){
        return;
    }
    //Look around to see if we can mark bad
    bool good = true;
    if(r > 0){
        if(field[r-1][c].first < block.first){
            //BAD
            good = false;
        }
    }
    if(r < field.size()-1){
        if(field[r+1][c].first < block.first){
            //BAD
            good = false;
        }
    }
    if(c < field[0].size()-1){
        if(field[r][c+1].first < block.first){
            //BAD
            good = false;
        }
    }
    if(c > 0){
        if(field[r][c-1].first < block.first){
            //BAD
            good = false;
        }
    }
    if(good){
        return;
    }
    //Bad!!!!!!!! Flood the elements of same size to be also bad.
    flood(field, r, c, block.first);
}

void solve(){
    int columns, rows; cin >> columns >> rows;
    vvpi field;
    for(int _r = 0; _r < rows; _r++){
        vector<pair<int, bool>> row;
        for(int _c = 0; _c < columns; _c++){
            int e; cin >> e;
            row.push_back({e, 0});
        }
        field.push_back(row);
    }
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            calculate(field, r, c);
        }
    }
    int count = 0;
    for(vpi &row : field){
        for(pair<int, bool> &block : row){
            count += !block.second;
        }
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}