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

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
typedef vector<vector<char>> vvc;

//returns the number of dots consumed
int flood(vvc &maze, pair<int, int> start, pair<int,int> &entrance){
    int consumed = 0;
    int row = start.first;
    int column = start.second;
    if((maze[row][column]!=' ') && (maze[row][column]!='.') && (start!=entrance)){
        return 0;
    }
    if(maze[row][column] == '.'){
        consumed++;
    }
    maze[row][column]='>';
    //up
    if(row!=0){
        consumed+=flood(maze, make_pair(row-1, column), entrance);
    }
    //down
    if(row < maze.size()-1){
        consumed+=flood(maze, make_pair(row+1, column), entrance);
    }
    //left
    if(column!=0){
        consumed+=flood(maze, make_pair(row, column-1), entrance);
    }
    //right
    if(column < maze[0].size()-1){
        consumed+=flood(maze, make_pair(row, column+1), entrance);
    }
    return consumed;
}
void solve(){
    int n, m; cin >> n >> m; string t; getline(cin, t);

    int entrances_used = 0;
    int dots_remaining = 0;

    vvc maze;
    vector<pair<int, int>> entrances;
    for(int r = 0; r < n; r++){
        string row;
        getline(cin, row);
        vector<char> rowlist;
        for(int col = 0; col < row.size(); col++){
            char c = row[col];
            if(c=='.'){
                dots_remaining++;
            }
            else if(c!=' ' && c!= 'X'){
                entrances.push_back(make_pair(r, col));
            }
            rowlist.push_back(c);
        }
        maze.push_back(rowlist);
    }
    for(pair<int, int> entrance : entrances){
        int consumed = flood(maze, entrance, entrance);
        if(consumed != 0){
            dots_remaining-=consumed;
            entrances_used++;
        }
    }
    cout << entrances_used << ' ' << dots_remaining << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}