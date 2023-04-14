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

void solve(){
    ll n; cin >> n;
    while(n--){
        double a, b, c; cin >> a >> b >> c;
        double sq = sqrt((b*b)-(4*a*c));
        if(sq == floor(sq)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}