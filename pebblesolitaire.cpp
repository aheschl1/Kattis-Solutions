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

map<vector<bool>, int> memo;

int best_game(vector<bool> board){
    if(memo.find(board) != memo.end()){
        return memo[board];
    }
    int min_with_move = 12;
    int pebbles = 0;
    for(int i = 0; i < 12; i++){
        //find pebbles to move
        if(board[i])pebbles++;
        if(!board[i]){
            continue;
        }
        bool right = false, left = false, two_right = true, two_left = true;
        if(i > 0){
            left = board[i-1];
        }
        if(i < 11){
            right = board[i+1];
        }
        if(i > 1){
            two_left = board[i-2];
        }
        if(i < 10){
            two_right = board[i+2];
        }

        
        if(left&&!two_left){
            //can jump left
            vector<bool> updated_board(board);
            updated_board[i] = false;
            updated_board[i-2]=true;
            updated_board[i-1] = false;
            min_with_move=min(min_with_move, best_game(updated_board));
        }
        if(right&&!two_right){
            //can jump right
            vector<bool> updated_board(board);
            updated_board[i]=false;
            updated_board[i+2]=true;
            updated_board[i+1] = false;
            min_with_move=min(min_with_move, best_game(updated_board));
        }
    }
    if(min_with_move == 12){
        memo[board]=pebbles;
        return pebbles;
    }
    memo[board]=min_with_move;
    return min_with_move;
}

void solve(){
    int T; cin >> T;
    while(T--){
        vector<bool> board;
        int i = 12;
        while(i--){
            char temp;cin>>temp;
            board.push_back(temp=='-'?false:true);
        }
        
        cout << best_game(board) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}