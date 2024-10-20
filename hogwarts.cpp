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

int DFS(vector<vector<int>> &senior, vector<vector<int>> &player, set<pair<int, int>> &visted_senior, int current_senior, int current_player){
    // Entry (i, x) shows what room you get to when you take exit x from room i
    // If x is -1, the exit is blocked
    // dorm is senior.length - 1
    int dorm_id = senior.size() - 1;
    if(current_senior == dorm_id && current_player != dorm_id){
        return 0;
    }
    bool result = true;
    int visited = 0;
    for(int path = 0; path < 4; path++){
        if(visted_senior.find({current_senior, path})==visted_senior.end() && senior[current_senior][path] != -1){
            visited += 1;
            visted_senior.insert({current_senior, path});
            // travel in this direction
            int r = DFS(senior, player, visted_senior, senior[current_senior][path], current_player != -1 ? player[current_player][path] : -1);
            if(r > -1){
                result = result&&r;
            }else{
                visited-=1;
            }
        }
    }
    if(visited == 0 && current_player == dorm_id && current_senior == dorm_id){
        return 1;
    }
    return visited > 0 ? result : -1;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> senior;
    vector<vector<int>> player;

    /**
     * fill the senior
     */
    for(int i = 0; i < n; i ++ ){
        vector<int> line;
        for(int x = 0; x < 4; x++){
            int w; cin >> w; 
            line.push_back(w-1);
        }
        senior.push_back(line);
    }

    /**
     * Fill the player
     */
    for(int i = 0; i < n; i ++ ){
        vector<int> line;
        for(int x = 0; x < 4; x++){
            int w; cin >> w; 
            line.push_back(w-1);
        }
        player.push_back(line);
    }

    // The task is to run a *FULL* DFS on the senior map, running the same steps on the player.
    // If the senior reaches the dorm, we check if the player is currently at the dorm.
    //      If so, we continue.
    //      If not, we output NO
    // If the DFS yields no paths, we output Impossible
    set<pair<int,int>> v;
    int r = DFS(senior, player, v, 0, 0);
    if(r == 0){
        cout << "No" << endl;
    }else if(r==1){
        cout << "Yes" << endl;
    }else{
        cout << "Impossible" << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}