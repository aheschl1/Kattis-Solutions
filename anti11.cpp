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
map<ull, ull> memo;
ull count(ull n, ull mod){
    
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }
    if(memo.find(n)!=memo.end()){
        return memo[n];
    }
    ull result = (count(n-1, mod)+count(n-2, mod));
    memo[n]=result%mod;
    return result%mod;
}

void solve(){
    ull mod = 1000000007;
    int T; cin >> T;
    while(T--){
        ull n; cin >> n;
        cout << count(n, mod)%mod << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}