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

void solve(){
    int n, k; cin >> n >> k;
    vector<deque<string>> owner_preferences;
    for(int i = 0; i < n; i++){
        int o; cin >> o;
        deque<string> p; 
        while(o--){
            string name; cin >> name;
            p.push_back(name);
        }
        owner_preferences.push_back(p);
    }
    deque<string> ranking;
    int u; cin>>u;
    while(u--){
        string name;cin >> name;
        ranking.push_back(name);
    }
    int selected_players = 0;
    int select_target = n*k;

    vector<vector<string>> teams (n, vector<string>());
    unordered_set<string> picked_players;

    while(selected_players < select_target){
        for(int curr_team = 0; curr_team < n; curr_team ++){
            // try to pick someone from the preference list
            string selected = "-1";
            if(!empty(owner_preferences[curr_team])){
                while(picked_players.find(owner_preferences[curr_team].front()) != picked_players.end()){
                    owner_preferences[curr_team].pop_front();
                    if(owner_preferences[curr_team].empty()){
                        break;
                    }
                }
                if(!empty(owner_preferences[curr_team])){
                    selected = owner_preferences[curr_team].front();
                    owner_preferences[curr_team].pop_front();
                }
            }
            if(selected == "-1"){
                // now use global prefeernce
                while(picked_players.find(ranking.front()) != picked_players.end()){
                    ranking.pop_front();
                }
                selected = ranking.front();
                ranking.pop_front();
            }
            selected_players += 1;
            picked_players.insert(selected);
            teams[curr_team].push_back(selected);
        }
    }

    for(vector<string> &team : teams){
        for(string &player : team){
            cout << player << ' ';
        }
        cout << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}