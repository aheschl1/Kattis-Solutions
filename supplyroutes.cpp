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
typedef vector<vector<int>> vvl;

unordered_map<int, int> unionfind;

int find_root(int k)
{
    if (unionfind[k] == k) {
        return k;
    }
    return unionfind[k] = find_root(unionfind[k]);
}
void union_subsets(int a, int b)
{
    int x = find_root(a);
    int y = find_root(b);
    unionfind[x] = y;
}

void solve(){
    int n, m, q; cin >> n >> m >> q;
    //0 = no road. 1 = road. 2 = overrun
    unordered_map<int, vector<int>> adjacency_list;
    for(int i = 0; i < n; i ++){
        unionfind[i] = i;
    }
    while(m--){
        int a, b; cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    deque<pair<int, pair<int, int>>> queries;
    deque<string> results;
    while(q--){
        int t; cin >> t;
        ll a, b; cin >> a >> b;
        if(t == 0){
            adjacency_list[a].erase(find(adjacency_list[a].begin(), adjacency_list[a].end(), b));
            adjacency_list[b].erase(find(adjacency_list[b].begin(), adjacency_list[b].end(), a));
        }
        queries.push_front({t, {a, b}});
    }
    for(pair<int, vector<int>> entry : adjacency_list){
        for(int a : entry.second){
            union_subsets(entry.first, a);
        }
    }

    for(pair<int, pair<int, int>> query : queries){
        if(query.first == 0){
            //connect
            union_subsets(query.second.first, query.second.second);
            
        }else{
            //query
            if(find_root(query.second.first) == find_root(query.second.second)){
                results.push_front("safe");
            }else{
                results.push_front("unsafe");
            }
        }
    }
    for(string result : results){
        cout << result << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}