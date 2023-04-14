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

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

int iters = 0;
map<pair<set<set<char>>, set<char>>, int> memo;

int min_quick(set<set<char>> performances_remaining, set<char> last_performers){
    if(performances_remaining.size() == 0){
        return 0;
    }
    if(memo.find(make_pair(performances_remaining, last_performers))!=memo.end()){
        return memo[make_pair(performances_remaining, last_performers)];
    }
    int min_val = 1000000;
    for(set<char> performance : performances_remaining){
        int current_min = 0;

        set<char> union_set;
        union_set.insert(performance.begin(), performance.end());
        union_set.insert(last_performers.begin(), last_performers.end());

        int overlap = (last_performers.size() + performance.size())-union_set.size();
        current_min=overlap;
        set<set<char>> mod(performances_remaining);
        mod.erase(mod.find(performance));
        current_min += min_quick(mod, performance);
        min_val = min(min_val, current_min);
    }

    memo[make_pair(performances_remaining, last_performers)] = min_val;

    return min_val;
}

void solve(){
    int N;cin>>N;
    set<set<char>> performances;
    while(N--){
        string p; cin >> p;
        set<char> per(p.begin(), p.end());
        per.insert(N);
        performances.insert(per);
    }
    int ans = min_quick(performances, {});
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}