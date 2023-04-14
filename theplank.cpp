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

int num_planks(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else if(n==3){
        return 4;
    }
    return num_planks(n-1) + num_planks(n-2) + num_planks(n-3);
}

void solve(){
    int n;
    cin >> n;
    cout << num_planks(n) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}