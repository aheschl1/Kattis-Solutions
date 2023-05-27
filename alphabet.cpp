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

int longest = 0;
unordered_set<string> visited;
string input;

void dp(int current_index, string current_value){
    string rep = current_value[current_value.size()-1] + to_string(current_index) + ' ' + to_string(current_value.size());
    longest = max((int)current_value.size(), longest);
    if(current_value[current_value.size()-1] == 'z'){
        return;
    }
    if(current_index == input.size()){
        return;
    }
    if(visited.find(rep) != visited.end()){
        return;
    }
    if(input[current_index] <= current_value[current_value.size()-1]){
        dp(current_index + 1, current_value);
    }else if(input[current_index] == (current_value[current_value.size()-1] + 1)){
        dp(current_index + 1, current_value + input[current_index]);
    }else{
        dp(current_index + 1, current_value);
        dp(current_index + 1, current_value + input[current_index]);
    }
    visited.insert(rep);
}

void solve(){
    cin >> input;
    dp(0, " ");
    cout << 26 - longest + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}