#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct node{
    vector<int> parents;
    //normal 0 success 1 dead 2
    int type = 0;
    ull in_degree = -1;
};

ull routes_to(unordered_map<int, node> &tree, int current){
    if(current == 1){
        return 1;
    }else if(tree[current].in_degree != -1){
        return tree[current].in_degree;
    }
    ull count = 0;
    for(int noden : tree[current].parents){
        count += routes_to(tree, noden);
    }
    tree[current].in_degree = count;
    return count;
}

void solve(){
    
    int t;
    cin >> t;
    while(t--){
        unordered_map<int, node> tree;
        set<int> favorable;
        int routes;
        cin >> routes;
        while(routes--){
            int name;
            cin >> name;
            string next;
            cin >> next;
            if(next[0] >= '0' && next[0] <= '9'){
                if(tree.find(name) == tree.end()){
                    node nn;
                    tree[name] = nn;
                }
                //num
                int childa = stoi(next);
                if(tree.find(childa) == tree.end()){
                    node nn;
                    nn.parents.push_back(name);
                    tree[childa] = nn;
                }else{
                    tree[childa].parents.push_back(name);
                }
                int j = 2;
                while(j--){
                    int childb;
                    cin >> childb;
                    if(tree.find(childb) == tree.end()){
                        node nn;
                        nn.parents.push_back(name);
                        tree[childb] = nn;
                    }else{
                        tree[childb].parents.push_back(name);
                    }
                }
            }else{
                if(next[0] == 'f'){
                    //favorable
                    favorable.insert(name);
                    if(tree.find(name) != tree.end()){
                        tree[name].type = 1;
                    }else{
                        node nn;
                        nn.type = 1;
                        tree[name] = nn;
                    }
                }else{
                    //dead
                    if(tree.find(name) != tree.end()){
                        tree[name].type = 2;
                        tree[name].in_degree = 0;
                    }else{
                        node nn;
                        nn.type = 2;
                        nn.in_degree = 0;
                        tree[name] = nn;
                    }
                }
            }
        }
        //tree has been built.
        ull ways = 0;
        for(int ending : favorable){
            ways += routes_to(tree, ending);
        }
        cout << ways << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}