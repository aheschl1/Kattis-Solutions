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
    string opponnent; cin >> opponnent;
    int n; cin >> n;
    vector<string> valid_start;
    map<char, vector<string>> starting_characters;
    while(n--){
        string t; cin >> t;
        if(t[0] == opponnent[opponnent.size()-1]){
            valid_start.push_back(t);
        }
        starting_characters[t[0]].push_back(t);
    }

    if(valid_start.size() == 0){
        cout << '?' << endl;
        return;
    }
    for(int i = 0; i < valid_start.size(); i++){
        string play = valid_start[i];
        char last_char = play[play.size()-1];
        int kill_length = 0;
        if(play[0] == last_char){
            kill_length = 1;
        }
        if(starting_characters[last_char].size() == kill_length){
            cout << play << '!' << endl;
            return;
        }
    }
    cout << valid_start[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}