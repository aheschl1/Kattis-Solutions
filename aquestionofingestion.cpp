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

typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

void solve(){
    ll n, m; cin >> n >> m;

    vi meals(n, 0);
    vi max_intakes;


    for(int i = 0; i < n; i++){
        cin >> meals[i];
    }
    ll c = m;
    for(int _ = 0; _ <= n; _++){
        max_intakes.push_back(c);
        // cout << c << ' ';
        c *= 2;
        c /= 3;
    }
    // cout << endl;
    // for(int i : meals){
    //     cout << i << ' ';
    // }
    // cout << endl << endl;
    
    vector<vector<pii>> dp(n, vector<pii>(max_intakes.size(), {-1, -1}));
    // setup first meal possibilities
    dp[0][0] = {0, -1}; // {no max, yes max}
    dp[0][1] = {-1, min(meals[0], m)};
    
    for(int r = 1; r < dp.size(); r++){
        ll meal = meals[r];
        // look at possible positions in row above
        for(int c = 0; c < dp[r].size()-1 /*We could only ever reach the last entry lookig back at the last row*/; c++){
            pii &current_entry = dp[r-1][c];
            if(current_entry.first == -1 && current_entry.second == -1){break;} // skip impossible circumstance
            if(current_entry.second != -1){
                ll cal = current_entry.second;                
                // eat
                ll nc = cal+min(max_intakes[c], meal);
                dp[r][c+1].second = max(dp[r][c+1].second, nc);
                // dpnt eat
                dp[r][c-1].first = max(dp[r][c-1].first, cal);
            }
            if(current_entry.first != -1){
                ll cal = current_entry.first;
                // eat
                ll nc = cal+min(max_intakes[c], meal);
                dp[r][c+1].second = max(dp[r][c+1].second, nc);
                // if we didn't eat last time, we can not eat now, and regenerate.
                dp[r][0].first = max(dp[r][0].first, cal);
            }
        }
    }

    // for(vector<pii> x : dp){
    //     for(pii &i : x){
    //         cout << i.first << "_" << i.second << " "; 
    //     }
    //     cout << endl;
    // }

    ll max_eat = -1;
    for(pii &x : dp[dp.size()-1]){
        max_eat = max(max_eat, x.first);
        max_eat = max(max_eat, x.second);
    }
    cout << max_eat << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}