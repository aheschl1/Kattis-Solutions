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

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

 int power(int a, int b){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % 1000000007; // multiplying with base
        }
        y = (y*y) % 1000000007; // squaring the base
        b /= 2;
    }
    return x % 1000000007;
}

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(power(a, power(b, c)) == power(power(a, b), c)){
        cout << "What an excellent example!" << endl;
    }else{
        cout << "Oh look, a squirrel!" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}