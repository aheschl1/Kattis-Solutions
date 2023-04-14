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
    ll n, k; cin >> n >> k;
    ll num = 0;
    ll count = 0;
    for(ll i = 1; i <= n; i++){
        num*=pow(10, (to_string(i).size()));
        num+=i;
        if(num%k == 0){
            count++;
        }
        num%=k;
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}