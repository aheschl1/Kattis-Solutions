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
#define sentinel -2147483647

using namespace std;

int do_thing(vector<int> &coordinates, int R){
    int r = 0;
    int l = r - 2*R;

    int best_x = sentinel;
    int best_potential = 0; 
    int potential = 0;
    while(r < coordinates.size()){
        potential += coordinates[r];
        if(l > 0){
            potential -= coordinates[l-1];
        }
        if(potential > best_potential){
            best_potential = potential;
            best_x = (l+r)/2;
        }
        
        l += 1;
        r += 1;
    }
    if(best_x != sentinel){
        for(int i = best_x - R; i <= best_x + R; i++){
            if(i >= 0 && i < coordinates.size()){
                coordinates[i] = 0;
            }
        }
    }
    
    return best_x;
}

void solve(){
    int n, R; cin >> n >> R;
    unordered_map<int, int> coordinates;
    int min_x = -sentinel;
    int max_x=sentinel;
    while(n--){
        int k; cin >> k;
        coordinates[k] += 1;
        if(k > max_x){
            max_x = k;
        }
        if(k < min_x){
            min_x = k;
        }
    }
    vector<int> positions(max_x-min_x + 1, 0);
    for(const auto &k : coordinates){
        positions[k.first-min_x] = k.second;
    }
    vector<int> bombs;
    int result = 0;
    do{
        result = do_thing(positions, R);
        if(result != sentinel){
            bombs.push_back(result+min_x);
        }
    }
    while(result != sentinel);
    cout << bombs.size() << endl;
    for(int i : bombs){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}