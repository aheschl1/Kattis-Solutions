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

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
    if(lhs.second == rhs.second) {
        return lhs.first < rhs.first;
    }
    return lhs.second < rhs.second;
}

void solve(){
    int UPPER = 1;
    int LOWER = 0;

    int n; cin >> n;
    vector<pair<int, int>> minions;
    for(int i = 0; i < n; i++){
        pair<int, int> minion;
        cin >> minion.first >> minion.second;
        minions.push_back(minion);
    }
    sort(minions.begin(), minions.end(), cmp);

    int room = 1;
    int threshold = minions[0].second;

    for(pair<int, int> minion: minions){
        if(minion.first > threshold){
            room += 1;
            threshold = minion.second;
        }
    }
    cout << room << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}