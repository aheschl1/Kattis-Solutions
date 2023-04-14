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

void insert(vvl &sequences, int bottom, int top, ll item){
    /*
    *0: {low}
    *1: {high}    
    */
   if(top <= bottom){
        //create new
        if(top == bottom){
            if(sequences[top][sequences[top].size()-1] < item){
                sequences[top].push_back(item);
                return;
            }
        }
        vector<ll> newv;
        newv.push_back(item);
        sequences.push_back(newv);
   }else{
        int mid = (bottom+top) / 2;
        if(item > sequences[mid][sequences[mid].size()-1]){
            //could fit
            if(mid == 0 || item <= sequences[mid-1][sequences[mid-1].size()-1]){
                //insert to mid
                sequences[mid].push_back(item);
            }else{
                //fits higher
                insert(sequences, bottom, mid-1, item);
            }
        }else{
            //fits lower
            insert(sequences, mid+1, top, item);
        }
   }
}

void solve(){
    ll n; cin >> n;
    vvl sequences;
    while (n--)
    {
        ll current; cin >> current;
        insert(sequences, 0, sequences.size()-1, current);

    }  
    cout << sequences.size() << endl;
    for(vector<ll> s : sequences){
        for(ll l : s){
            cout << l << ' ';
        }
        cout << endl;
    }   

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}