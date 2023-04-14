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

void solve(){
    int N; cin >> N;
    bool possible[2000];
    for(int i = 0; i < 2000; i++){
        possible[i] = false;
    }
    possible[0] = true;
    while(N--){
        int w; cin >> w;
        for(int i = 1999; i > 0; i--){
            if(possible[i]){
                if(i+w < 2000){
                    possible[i+w] = true;
                }
            }
        }
        possible[w] = true; 
    }
    for(int off = 0; off <= 1000; off++){
        if(possible[1000+off]){
            cout << 1000+off << endl;
            break;
        }else if(possible[1000-off]){
            cout << 1000-off << endl;
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}