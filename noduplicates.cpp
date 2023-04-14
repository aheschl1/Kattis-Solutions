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

using namespace std;

void solve(){
    set<string>  words;
    string word;
    while(cin>>word){
        if(words.find(word) != words.end()){
            cout << "no" << endl;
            return;
        }else{
            words.insert(word);
        }
    }
    cout << "yes" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}