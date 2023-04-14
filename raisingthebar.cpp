#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<string>
#include<deque>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
    int n, d; cin >> n >> d;
    vector<int> ordered_remainders;
    unordered_set<int> remainders;
    while(true){
        int remainder = n%d;
        if(remainder == 0){
            cout << remainders.size() << " 0" << endl;
            break;
        }
        if(remainders.find(remainder) != remainders.end()){
            int index = find(ordered_remainders.begin(), ordered_remainders.end(), remainder) - ordered_remainders.begin();
            cout << index << ' ' << remainders.size()-index << endl;
            break;
        }
        remainders.insert(remainder);
        ordered_remainders.push_back(remainder);
        n=remainder;
        n*=10;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}