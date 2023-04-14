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
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
typedef vector<priority_queue<ull>> vpi;

unordered_map<string, ull> memo;

void solve(){
    ull N, T;
    cin >> N >> T;
    unordered_map<ull, set<ull>> queue;
    priority_queue<ull> possible_money;
    ull taken = 0;
    while(N--){
        ull money, time; cin >> money >> time;
        queue[time].insert(money);
    }
    for(int time = T-1; time > -1; time--){
        if(queue.find(time) == queue.end()){
            continue;
        }
        for(int c : queue[time]){
            possible_money.push(c);
        }
        taken+=possible_money.top();
        possible_money.pop();
    }
    cout << taken << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}