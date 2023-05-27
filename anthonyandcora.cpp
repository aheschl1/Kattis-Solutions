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

typedef vector<vector<double>> vvd;

void solve(){
    int lives, wins_required; cin >> lives >> wins_required;
    int n = lives + wins_required - 1;

    vvd table(n+1, vector<double>(wins_required+1, 0));
    double ans = 0;
    for(int g = 0; g < n; g++){
        double p; cin >> p;
        if(g==0){
            table[0][0] = 1-p;
            table[0][1] = p;
            if(wins_required==1){
                ans+=p;
            }
            continue;
        }
        for(int w_b = 0; w_b < wins_required; w_b ++){
            if(g-w_b < lives){
                double p_b = table[g-1][w_b];
                table[g][w_b] += p_b*(1-p);
                table[g][w_b+1] += p_b*(p);
                if(w_b+1 == wins_required){
                    ans+=p_b*(p);
                }
            }
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