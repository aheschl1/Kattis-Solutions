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
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
struct node{
    ll parent = -1;
    vi children;
};

ll k;
//          color of node
//
//          0 1 2 3
// node 0   child sum if this
//      1
//      2
//      3  
//      4

ll get_optimal(ll da_node_index, ll illegal, vector<node> &tree, vvi &dp){
    if(dp[da_node_index][illegal]!=-1){
        return dp[da_node_index][illegal];
    }
    node &da_node = tree[da_node_index];
    if(da_node.children.size() == 0){
        if(illegal == 1){
            dp[da_node_index][illegal] = k >= 2 ? 2 : INT32_MAX;
            return k >= 2 ? 2 : INT32_MAX;
        }else{
            dp[da_node_index][illegal] = 1;
            return 1;
        }
    }
    ll optimal = INT32_MAX;
    for(ll c = 1; c <= k; c++){
        if(c == illegal){
            continue;
        }
        ll children_optimal = 0;
        for(ll child : da_node.children){
            children_optimal+=get_optimal(child, c, tree, dp);
        }
        optimal = min(optimal, c + children_optimal);
    }
    dp[da_node_index][illegal] = optimal;
    return optimal;
}

void build_tree(ll current, vector<node> &tree, unordered_map<ll, vi> &adjacency){
    for(ll n : adjacency[current]){
        if(n!=tree[current].parent){
            tree[current].children.push_back(n);
            tree[n].parent = current;
            build_tree(n, tree, adjacency);
        }
    }
}

void solve(){
    ll n;cin>>n>>k;
    ll l = n-1;

    //0th node DNE
    vector<node> tree(n+1, node());
    unordered_map<ll, vi> adjacency;
    //build adjacency
    while(l--){
        ll a, b; cin >> a >> b;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    //build tree rooted at 1. This is arbitrary.
    ll root = 1;
    build_tree(root, tree, adjacency);
    //            1
    //          /   \
    //        2      3    I hate trees
    //       / \    /  \
    //      4   5   6   7
    vvi dp(n+1,vector<ll>(k+1,-1));
    ll optimal = get_optimal(root, 0 ,tree, dp);
    cout << (optimal == INT32_MAX ? -1 : optimal) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}