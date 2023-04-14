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

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;

using namespace std;

void solve(){
    unordered_map<string, vector<ui>> trips;
    ui t; cin >> t;
    while(t--){
        string country; cin >> country;
        ui year; cin >> year;
        trips[country].push_back(year);
    }
    for( auto &[key, value]: trips ){
        sort(value.begin(), value.end());
    }
    ui queries; cin >> queries;
    while(queries--){
        string country; cin >> country;
        ui t; cin >> t;
        cout << trips[country][t-1] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}