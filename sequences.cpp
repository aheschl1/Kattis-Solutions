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

typedef vector<vector<ll>> vvl;

struct element{
    ll zeroes = 0;
    ll questions = 0;
    bool is_question = false;
    string rep(){
        return to_string(zeroes) + ' '  + to_string(questions) + ' '  + to_string(is_question);
    }
};

unordered_map<ll, vector<ll>> paskal_rows;

ll modpow(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll mod = 1000000007;
    string input; cin >> input;

    ll total_question = 0;
    ll total_zeroes = 0;
    ll count = 0;

    for(ll i = input.size()-1; i >= 0; i--){
        char c = input[i];
        if(c == '1'){
            ll z = total_zeroes * modpow(2, total_question, mod);
            ll q = total_question == 0 ? 0 : total_question * modpow(2, total_question-1, mod);
            count += (z+q);
        }else if(c=='0'){
            total_zeroes+=1;
        }else{
            count*=2;
            ll z = total_zeroes * modpow(2, total_question, mod);
            ll q = total_question == 0 ? 0 : total_question * modpow(2, total_question-1, mod);
            count += (z+q);
            total_question+=1;
        }
        count%=mod;
    }

    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}