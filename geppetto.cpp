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

int combos(int i, set<int> current, vector<int> &ingredients, map<int, set<int>> &restrictions){
    if(i >= ingredients.size()){
        return 1;
    }
    int ingredient = ingredients[i];
    int count = 0;
    //without
    count += combos(i+1, current, ingredients, restrictions);
    //with
    bool add = true;
    for(int ing : current){
        set<int> illegal = restrictions[ing];
        if(illegal.find(ingredient) != illegal.end()){
            add = false;
            break;
        }
    }
    if(add){
        current.insert(ingredient);
        count += combos(i+1, current, ingredients, restrictions);
    }
    return count;
}

void solve(){
    map<int, set<int>> restrictions;
    vector<int> ingredients;
    int c, restriction;
    cin >> c >> restriction;
    while(c--){
        ingredients.push_back(c+1);
    }
    while(restriction--){
        int a, b;
        cin >> a >> b;
        restrictions[a].insert(b);
        restrictions[b].insert(a);
    }
    cout << combos(0, {}, ingredients, restrictions) << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}