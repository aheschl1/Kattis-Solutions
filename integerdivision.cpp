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
    ll n, d; cin >> n >> d;
    
    vector<ll> nums;
    unordered_map<ll, pair<ll, ll>> quotients;

    for(int i = 0; i < n; i ++){
        ll x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    for(ll i : nums){
        ll q = i/d;
        if(quotients.find(q) == quotients.end()){
            quotients[q] = {1, 0};
        }else{
            pair<ll, ll> curr = quotients[q];
            quotients[q] = {curr.first+1, curr.second + curr.first};
        }
    }

    ll r = 0;
    for(const pair<ll, pair<ll, ll>> &p : quotients){
        r += p.second.second;
    }
    cout << r << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}