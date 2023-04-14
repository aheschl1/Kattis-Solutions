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
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct Kitty{
    ull infection;
    ull time_admitted;
    string name;
    bool operator < (const Kitty & b) const{
        if(infection != b.infection){
            return infection > b.infection;
        }
        return time_admitted > b.time_admitted;
    }
    
};

void solve(){
    int N; cin >> N;
    map<string, Kitty> catmap;
    set<Kitty> cats;
    while(N--){
        int type; cin >> type;
        if(type==0){
            //new cat
            string name;
            ull infection; 
            cin >> name >> infection;
            Kitty n;
            n.time_admitted = N;
            n.name = name;
            n.infection = infection;
            catmap[name] = n;
            cats.insert(n);            
        }else if(type == 1){
            //update
            string name;
            ull infection;
            cin >> name >> infection;
            auto it = cats.find(catmap.at(name));
            cats.erase(it);
            catmap.at(name).infection+=infection;
            cats.insert(catmap[name]);
        }else if(type==2){
            //treated
            string name; cin >> name;
            cats.erase(cats.find(catmap.at(name)));
            catmap.erase(name);
        }else{
            if(catmap.size() == 0){
                cout << "The clinic is empty" << endl;
            }else{
                //find max cat                
                cout << (*cats.begin()).name << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}