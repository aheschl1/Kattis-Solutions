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

void solve(){
    int n, X; cin >> n >> X;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vector<int> values; 
    while(n--){
        int t; cin >> t;
        values.push_back(t);
    }
    int total = 0;
    sort(values.begin(), values.end());
    for(int i = 0; i < values.size()-1; i++){
        if(values[i] + values[i+1] <= X){
            total+=1;
        }
    }
    cout << total + 1<< endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}