#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<deque>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void balance(deque<int> &bottom, deque<int> &top){
    const int topsize = top.size();
    int bottomsize = bottom.size();
    if(topsize-1 > bottomsize){
        int diff = topsize - bottomsize;
        for(int i = 0; i < diff/2; i++){
            bottom.push_back(top[0]);
            top.pop_front();
        }
    }else if(bottomsize-1 > topsize){
        int diff = bottomsize - topsize;
        for(int i = 0; i < diff/2; i++){
            top.push_front(bottom[bottomsize-1]);
            bottom.pop_back();
            bottomsize--;
        }
    }
}

void solve(){
    int num_commands; cin >> num_commands;
    deque<int> bottom, top;
    while(num_commands--){
        string command; cin >> command;
        int val; cin >> val;
        if(command == "push_back"){
            top.push_back(val); // 1
        }else if(command == "push_front"){
            bottom.push_front(val); //1
        }else if(command == "push_middle"){
            if(bottom.size() > top.size()){
                top.push_front(val);
            }else if(top.size() > bottom.size()){
                bottom.push_back(top[0]);
                top.pop_front();
                top.push_front(val);
            }else{
                bottom.push_back(val);
            }
        }else{
            if(val >= bottom.size()){
                //top
                int i = val - bottom.size();
                cout << top[i] << endl;
            }else{
                cout << bottom[val] << endl;
            }
        }
        balance(bottom, top);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}