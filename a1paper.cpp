#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<iomanip>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

map<int, pair<double, double>> tape;

void genTapeMap(map<int, pair<double, double>> &tape,  int max, int size = 2){
    double width, height;
    if(size == 2){
        const pair<int, pair<double, double>> thing = make_pair(2, make_pair(pow(2, (double)-5/(double)4), pow(2, (double)-3/(double)4)));
        tape.insert(thing);
    }else{
        pair<double, double> prev = tape[size-1];
        if(size%2){
            prev.second /= 2;
        }else{
            prev.first /= 2;
        }
        tape[size] = prev;
    }

    if(!(size == max)){
        genTapeMap(tape, max, size + 1);
    }
}

bool build(map<int, int> &papers_available, int goal, int count){
    for(pair<int, int> papers : papers_available){
        int size = papers.first;
        int quantity = papers.second;
        int required = pow(2, size-goal)*count;
        if(quantity <= 0){
            continue;
        }
        if(quantity >= required){
            papers_available[size] -= required;
            return true;
        }else{
            if(quantity < required){ 
                int new_goal = size;
                int to_be_made = required-quantity;
                papers_available[size] = 0;
                return build(papers_available, new_goal, to_be_made);
            }
        }
    }
    return false;
}
void solve(){    
    unsigned int smallest_size;
    map<int, int> papers_available;
    vector<ll> quantities;

    cin >> smallest_size;
    for(int i = 2; i <= smallest_size; i++){
        unsigned int temp;
        cin >> temp;
        quantities.push_back(temp);
        papers_available[i] = temp;
    }

    genTapeMap(tape, smallest_size);
    bool result = build(papers_available, 1, 1);
    double longedge = tape[2].second;
    double shortedge = tape[2].first;
    double totaltape = 0;
    ll needed = 1;
    if(result){
        for(ll i = 0; i < smallest_size - 1; i++) { //biggest firts
            // Calculate cost here
            totaltape += needed * longedge;
            swap(shortedge, longedge);
            shortedge /= 2;

            // Calculate paper needed now
            needed *= 2;
            needed -= quantities[i];            
        }
        cout << fixed << totaltape << setprecision(11) << endl;
    }else{
        cout << "impossible" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}