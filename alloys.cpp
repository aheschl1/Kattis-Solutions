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
    double p; cin >> p;
    p = min(1.0, p);
    cout << pow(p, 2.0)/4.0 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}