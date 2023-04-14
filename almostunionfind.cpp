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

unordered_map<int, int> unionfind;

// Find the root of the set in which element `k` belongs
int find(int k)
{
    if (unionfind[k] == k) {
        return k;
    }
    return unionfind[k] = find(unionfind[k]);
}

// Perform Union of two subsets
void Union(int a, int b)
{
    // find the root of the sets in which elements `x` and `y` belongs
    int x = find(a);
    int y = find(b);
    
    unionfind[x] = y;
}

void solve(){
    ll n, m;
    while(cin >> n >> m){
        //            set id    count sum
        unordered_map<ll, pair<ll, ll>> sets;
        //            num  set id
        unordered_map<ll, ll> numbers;
        unionfind = unordered_map<int, int>();
        for(ll i = 0; i < n; i ++){
            unionfind[i] = i;
            sets[i] = make_pair(1, i+1);
            numbers[i+1] = i;
        }
        while(m--){
            ll command; cin >> command;
            if(command == 1){
                ll p, q; cin >> p >> q;
                //union set with p to set with q
                ll p_set = find(numbers[p]);
                ll q_set = find(numbers[q]);
                if(p_set != q_set){
                    sets[p_set].first += sets[q_set].first;
                    sets[p_set].second += sets[q_set].second;
                    sets[q_set] = make_pair(0, 0);
                    Union(q_set, p_set);
                }
            }else if(command == 2){
                ll p, q; cin >> p >> q;
                //move p to set with q
                ll p_set = find(numbers[p]);
                ll q_set = find(numbers[q]);
                if(p_set != q_set){
                    sets[q_set].first += 1;
                    sets[q_set].second += p;
                    sets[p_set].second-=p;
                    sets[p_set].first-=1;
                    numbers[p] = q_set;
                }
            }
            else{
                ll p; cin >> p;
                ll p_set = find(numbers[p]);
                cout << sets[p_set].first << ' ' << sets[p_set].second << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}