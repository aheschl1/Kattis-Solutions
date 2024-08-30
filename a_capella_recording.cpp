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
    vector<ll> pitches;
    while(n--){
        ll i; cin >> i;
        pitches.push_back(i);
    }
    int iters = 0;
    int max = -1;
    sort(pitches.begin(), pitches.end());
    for(int i = 0; i < pitches.size(); i++){
        ll val = pitches[i];
        if(val > max){
            iters += 1;
            max = val+d;
        }
    }
    cout << iters << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
