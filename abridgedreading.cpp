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
    int n, m; cin >> n >> m;

    vector<int> chapter_length(n+1, 0);
    vector<bool> is_culminating(n+1, true);
    vector<int> dependencies_list(n+1,0);

    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        chapter_length[i] = t;
        dependencies_list[i]=i;
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        dependencies_list[b] = a;
        is_culminating[a] = false;
    }
    vector<int> culminating;
    for(int i = 1; i < is_culminating.size(); i++){
        if(is_culminating[i]){
            culminating.push_back(i);
        }
    }
    int min_reading = INT32_MAX;
    for(int a = 0; a < culminating.size()-1; a++){
        for(int b = a+1; b < culminating.size(); b++){
            if(b != a){
                unordered_set<int> requirements = {culminating[a], culminating[b]};
                int location = culminating[a];
                while(dependencies_list[location] != location){
                    requirements.insert(dependencies_list[location]);
                    location = dependencies_list[location];
                }
                location = culminating[b];
                while(dependencies_list[location] != location){
                    requirements.insert(dependencies_list[location]);
                    location = dependencies_list[location];
                }
                int sum = 0;
                for(int i : requirements){
                    sum+=chapter_length[i];
                }
                min_reading = min(min_reading, sum); 
            }
        }
    }
    cout << min_reading << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}