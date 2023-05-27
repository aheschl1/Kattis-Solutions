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

void solve(){
    int d, u; cin >> d >> u;
    priority_queue<int, std::vector<int>, std::greater<int>> names;
    int reserved[4*100001];
    int day = 1;
    while(u--){
        names.push(day);
        if(reserved[day] != 0){
            names.push(reserved[day]);
            reserved[day] = 0;
        }
        char command; cin >> command;
        if(command == 'a'){
            if(!names.empty()){
                cout << names.top() << endl;
                names.pop();
            }
        }else{
            int name; cin >> name;
            reserved[day+d] = name;
        }
        day++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}