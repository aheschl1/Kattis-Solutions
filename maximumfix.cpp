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
    vector<ll> elements;
    while(n--){
        ll t; cin >> t;
        elements.push_back(t);
    }
    //          num count
    unordered_map<ll,ll> offest_reocurance; 

    for(ll i = 0; i < elements.size(); i++){
        ll element = elements[i];
        ll offset = element-(i+1);
        if(offset <= 0){
            offest_reocurance[abs(offset)]+=1;
        }else{
            offest_reocurance[elements.size()-offset]+=1;
        }
    }

    pair<ll,ll> best = {-1,-1};
    for(pair<ll,ll> p : offest_reocurance){
        if(p.second > best.second){
            best = p;
        }else if(p.second == best.second){
            if(p.first < best.first){
                best = p;
            }
        }
    }

    cout << abs(best.first) << ' ' << best.second << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}