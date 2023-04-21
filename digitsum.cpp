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

ll sum(string num){
    ll ans = 0;
    for(int k = 0; k < num.size(); k++){
        int dig_k = num[k]-'0';
        ll my_loc = pow(10, num.size()-k-1);
        ll local_count = 0;
        ll num_before = 0;
        ll num_after = 0;

        for(short w = 0; w <= k-1; w++){
            //get num before k
            int dig_w = num[w] - '0';
            num_before += (dig_w*pow(10, num.size()-(num.size()-k) - (w+1)));
        }
        for(short w = k+1; w <= num.size() - 1; w++){
            //num aftyer k
            int dig_w = num[w] - '0';
            int w_p = w-k;
            int n_p = num.size()-k-1;
            num_after += ( dig_w*pow(10, n_p - w_p));
        }

        for(short i = 0; i <= 9; i++){
            ll local = num_before;
            if(i < dig_k){
                local+=1;
            }
            local*=my_loc;
            if(i==dig_k){
                local+=1;
                local+=num_after;
            }
            ans+=(local*i);
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    while(n--){
        ll a, b; cin >> a >> b;
        string lower_bound = to_string(a == 0 ? a : a-1);
        string upper_bound = to_string(b);

        cout << sum(upper_bound) - sum(lower_bound) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}