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
    ll n, k; cin >> n >> k;
    //arival = 0, departure = 1
    vector<pair<ll, bool>> slots;
    while(n--){
        ll a, b; cin >> a >> b;
        a = max((ll)0, a-k);
        slots.push_back(make_pair(a, 0));
        slots.push_back(make_pair(b, 1));
    }
    sort(slots.begin(), slots.end());
    ll max_overlap = 0;
    ll overlap = 0;
    for(pair<ll, bool> p : slots){
        if(!p.second){
            //arival
            overlap += 1;
            max_overlap = max(max_overlap, overlap);
        }else{
            overlap--;
        }
    }
    cout << max_overlap << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}