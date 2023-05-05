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

string count_to_m(int m){
    string s = "";
    for(int i = 1; i <= m; i++){
       s += to_string(i) + ' ';
    }
    return s;
}

string count_to_m(int st, int m){
    string s = "";
    for(int i = st; i <= m; i++){
       s += to_string(i) + ' ';
    }
    return s;
}

void solve(){
    int m; cin >> m;
    if(m == 1){
        cout << 1 << endl << 1 << endl;
    }else if(m == 2){
        cout << 1 << endl << 2 << endl;
    }else if(m == 3){
        cout << 2 << endl << "1 2" << endl;
    }else if(m%4 == 0){
        cout << m << endl << count_to_m(m) << endl;
    }else if((m-1)%4==0){
        cout << m - 1 << endl << count_to_m(m-2) << m << endl;
    }else if((m-2)%4==0){
        cout << m - 1 << endl << count_to_m(2, m-1) << m << endl;
    }else if((m-3)%4==0){
        cout << m - 1 << endl << count_to_m(m-1) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}