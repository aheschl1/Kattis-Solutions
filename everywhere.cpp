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
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        set<string> places;
        while(n--){
            string t;
            cin >> t;
            places.insert(t);
        }
        cout << places.size() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}