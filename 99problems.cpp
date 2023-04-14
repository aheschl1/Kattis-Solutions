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
    double N;
    cin >> N;
    ull lower_whole, upper_whole;
    lower_whole = floor((N/100))*100;
    upper_whole = ceil((N/100))*100;
    if(lower_whole > 0){
        lower_whole--;
    }else{
        cout << upper_whole-1 << endl;
        return;
    }
    
    upper_whole--;
    int upper_diff = upper_whole - N;
    int lower_diff = N - lower_whole;
    cout << ((upper_diff < lower_diff) || (upper_diff==lower_diff) ? upper_whole : lower_whole) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}