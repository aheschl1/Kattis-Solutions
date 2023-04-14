#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
    int cards_count;
    cin >> cards_count;
    vector<int> card_list;
    while(cards_count--){
        int t;
        cin >> t;
        card_list.push_back(t);
    }
    while(true){
        bool madechange = false;
        for(int i = 0; card_list.size() > 0 && i < card_list.size()-1; i++){
            if(!((card_list[i] + card_list[i+1]) % 2)){
                //even;
                card_list.erase(card_list.begin() + i + 1);
                card_list.erase(card_list.begin() + i);
                i = 0;
                madechange = true;
            }
        }
        if(!madechange){
            break;
        }
    }
    cout << card_list.size() << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}