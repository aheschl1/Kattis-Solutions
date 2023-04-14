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

void calc(ll &spidey_unique, ll &total_spidey, ll t, ll s){
    for(ll diag = 0; ;diag++){
        ll remaining_range_spidey = s-ceil(1.5*(double)diag);
        ll remaining_range_taxi = t-(2*diag);
        ll new_spidey, new_taxi = 0;
        if(remaining_range_spidey < 0){
            break;
        }
        if(diag == 0){
            new_spidey = remaining_range_spidey*4 + 1;
            if(remaining_range_taxi >= 0){
                new_taxi = remaining_range_taxi*4 + 1;
            }
        }else{
            new_spidey = (remaining_range_spidey*2 + 1)*4;
            if(remaining_range_taxi >= 0){
                new_taxi = (remaining_range_taxi*2 + 1)*4;
            }
        }
        total_spidey+=new_spidey;
        if(new_spidey > new_taxi){
            spidey_unique+=(new_spidey-new_taxi);
        }
    }
}

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
    ll t, s;
    cin >> t >> s;
    ll spidey_unique = 0;
    ll total_spidey = 0;
    calc(spidey_unique, total_spidey, t, s);
    if(spidey_unique == 0){
        cout << '1' << endl;
        return;
    }
    ll numerator = total_spidey - spidey_unique;
    ll denom = total_spidey;

    ll gcd_d = gcd(numerator, denom);
    cout << numerator/gcd_d << '/' << denom/gcd_d << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}