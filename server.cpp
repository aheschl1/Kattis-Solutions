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
    int n, T;
    cin >> n >> T;
    int completed = 0;
    while(n--){
        int task;
        cin >> task;
        if(T-task >= 0){
            T-=task;
            completed++;
        }else{
            break;
        }
    }
    cout << completed << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}