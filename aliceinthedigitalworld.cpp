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
    int n, m; cin >> n >> m;

    vector<int> content;
    content.push_back(-1);
    vector<pair<int, char>> pois;
    pois.push_back({0, 'e'});
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        content.push_back(t);
        if(t < m){
            pois.push_back({i+1, 'e'});
        }else if(t == m){
            pois.push_back({i+1, 'm'});
        }
    }
    pois.push_back({content.size(), 'e'});
    content.push_back(-1);

    int ans = 0;

    for(int poi = 0; poi < pois.size(); poi++){
        char type = pois[poi].second;

        if(type == 'm'){
            int start = pois[poi-1].first + 1;
            int end = pois[poi+1].first - 1;

            int result = 0;
            for(int i = start; i <= end; i++){
                result += content[i];
            }
            ans = max(ans, result);
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    while(n--){
        solve();
    }
    return 0;
}