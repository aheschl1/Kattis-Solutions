
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

ll gcd(ll a, ll b){

    if (b > a){
        ll temp = a;
        a = b;
        b = temp;
    }

    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }

    ll remainder = a % b;

    return gcd(b,remainder);

}

void solve(){
    int a, b;
    cin >> a;
    cin.ignore();
    cin >> b;

    int numer, denom;
    numer = 5*a - (5*32*b);
    denom = 9*b;
    
    int fact = gcd(abs(numer), abs(denom));
    numer/=fact;
    denom/=fact;
    cout << numer << '/' << denom << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}