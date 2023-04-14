#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<stack>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
    string l;
    getline(cin, l);
    string out = "";
    for(char c : l){
        if(c == '<'){
            out.pop_back();
        }else{
            out += c;
        }
    }
    cout << out << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}