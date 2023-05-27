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
#include<iomanip>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct node{
    double pipe = -1;
    int parent = -1;
    bool power_pipe = false;
};

void solve(){
    int n; cin >> n;
    vector<node> tree(n+1);
    for(int i = 0; i < n-1; i++){
        int p, c, pow; double prob; cin >> p >> c >> prob >> pow; prob /= 100.0;
        
        tree[c].parent = p;
        tree[c].power_pipe = pow;
        tree[c].pipe = prob;
    }
    double ans = 0;
    for(int pipe = 1; pipe <= n; ++pipe){
        double r; cin >> r;
        if(r == -1){
            continue;
        }

        int location = pipe;
        while(true){
            if(tree[location].parent == -1){
                ans = max(r, ans);
                break;
            }
            if(tree[location].power_pipe){
                r = sqrt(r);
            }
            r /= tree[location].pipe;
            location = tree[location].parent;
        }
    }
    printf("%.3f\n", ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}