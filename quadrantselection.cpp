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

void solve(){
    int x,y;
    cin >> x >> y;
    if(x < 0 && y < 0){
        cout << 3 << endl;
    }else if(x < 0 && y > 0){
        cout << 2 << endl;
    }else if(x > 0 && y > 0){
        cout << 1 << endl;
    }else{
        cout << 4 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}