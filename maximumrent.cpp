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

int optimal_x(int &s, int &m, int min, int max){
    int x_mid = min + (max-min)/2;
    int y = m-x_mid;
    if(min == max){
        return min;
    }
    // find min x s.t. 2x + y >= s
    if(2*x_mid + y >= s && (2*(x_mid-1) + y+1 < s)){
        return x_mid;
    }
    if(2*x_mid + y < s){
        return optimal_x(s, m, x_mid+1, max);
    }
    return optimal_x(s, m, min, x_mid-1);
}

void solve(){
    int a, b, m, s;
    cin >> a >> b >> m >> s;
    //ez mode. maximize x
    if(a >= b){
        cout << a*(m-1) + b << endl;
        return;
    }
    //not ez mode
    int x = optimal_x(s, m, 1, m-1);
    int y = m-x;

    cout << a*x + b*y << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}