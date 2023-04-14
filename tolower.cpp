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
    //97 - 122
    int P, T; cin >> P >> T;
    int ans = 0;
    while(P--){
        int local = 0;
        for(int i = 0; i < T; i++){
            string t; cin >> t;
            bool works = true;
            for(int c = 1; c < t.size(); c++){
                char ch = t[c];
                if(! (ch >= 97 && ch <= 122)){
                    works = false;
                }
            }
            if(works){
                local += 1;
            }
        }
        if(local == T){
            ans += 1;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}