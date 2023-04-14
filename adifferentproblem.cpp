#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include <stdlib.h> 

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
    ll a, b;
    while(cin >> a){
        cin >> b;
        cout << abs(a-b) <<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}