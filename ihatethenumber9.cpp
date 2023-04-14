#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
ll power(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

void solve(){
    ull t;
    cin >> t;
    while(t--){
        ull m;
        cin >> m;
        cout << (8*power(9, m-1, 1000000007))%1000000007<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

