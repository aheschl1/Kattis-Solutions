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

void solve(){
    int P, W, L;
    cin >> P >> W >> L;
    map<string, int> scores;
    set<string> won;
    while(P--){
        string n; cin >> n;
        scores[n] = 0;
    }
    while(L--){
        string name;
        int scored;
        cin >> name >> scored;
        if((scores[name] + scored >= W) && (won.find(name) == won.end())){
            won.insert(name);
            cout << name << " wins!" << endl;
        }else{
            scores[name] += scored;
        }
    }
    if(won.size()==0){
        cout << "No winner!" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}