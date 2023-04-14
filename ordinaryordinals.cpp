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
    ull n, m;
    cin >> n >> m;
    if(n == 0){
        cout << 2%m << endl;
        return;
    }
    ull result = (5 * power(2, n-1, m)-1)%m; //b
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}