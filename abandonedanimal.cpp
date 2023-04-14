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

//Last visited

struct entry{
    int store;
    int freq;
    int max_freq;
};

void solve(){
    ll num_stores; cin >> num_stores;

    unordered_map<string, vector<ll>> item_availability;

    ll k; cin >> k;
    while(k--){
        ll store; 
        string item;
        cin >> store >> item;
        item_availability[item].push_back(store);
    }
    ll num_items; cin >> num_items;
    string first_item;
    cin >> first_item;
    num_items--;
    vector<entry> *previous_marked = new vector<entry>;
    for(ll store : item_availability[first_item]){
        entry e;
        e.store = store;
        e.freq = 1;
        e.max_freq = 1;
        previous_marked->push_back(e);
    }
    while(num_items--){
        string item;
        cin >> item;
        bool can_access = false;
        vector<entry> *current_marked = new vector<entry>;
        for(ll shop : item_availability[item]){
            ll new_f = 0;
            ll max_freq = 0;
            for(entry old_e : *previous_marked){
                //last at same store
                if(old_e.store <= shop){
                    new_f += 1;
                    if(old_e.max_freq > max_freq){
                        max_freq = old_e.max_freq;
                    }
                    if(old_e.freq > max_freq){
                        max_freq = old_e.freq;
                    }
                }
            }
            if(new_f > 0){
                entry e;
                e.store = shop;
                e.freq = new_f;
                e.max_freq = max_freq;
                current_marked->push_back(e);
                can_access = true;
            }
        }
        delete previous_marked;
        previous_marked = current_marked;
        if(!can_access){
            cout << "impossible" << endl;
            return;
        }
    }
    ll count = 0;
    entry final_shop;
    for(entry &solution : *previous_marked){
        count += 1;
        final_shop = solution;
        if(count > 1){
            cout << "ambiguous" << endl;
            return;
        }
    }
    if(count == 1){
        if(final_shop.max_freq == 1 && final_shop.freq == 1){
            cout << "unique" << endl;
        }else{
            cout << "ambiguous" << endl;
        }
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}