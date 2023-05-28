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
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

typedef vector<vector<int>> vvi;

void display(vvi &matrix){
    for(vector<int> row : matrix){
        for(int i : row){
            cout << i << ' ';
        }
        cout << endl;
    }
}

void solve(){
    int n; cin >> n;
    vector<int> menu;
    vector<int> orders;
    while(n--){
        int t; cin >> t;
        menu.push_back(t);
    }
    cin >> n;
    while(n--){
        int t; cin >> t;
        orders.push_back(t);
    }
    vvi matrix(30000+1, vector<int>(menu.size(), 0));
    
    unordered_set<int> impossible_list;
    unordered_set<int> ambiguous_list;
    unordered_set<int> visited_sums; visited_sums.insert(0);

    for(int i = 0; i < matrix.size(); i++){
        vector<int> &row = matrix[i];
        bool is_ambiguous = (ambiguous_list.find(i) != ambiguous_list.end());
        bool is_possible = (visited_sums.find(i) != visited_sums.end());
        if(!is_possible){
            impossible_list.insert(i);
            continue;
        }
        for(int item_index = 0; item_index < menu.size(); item_index++){
            int item = menu[item_index];
            vector<int> new_row(row.begin(), row.end());
            new_row[item_index] += 1;

            int new_sum = i+item;
            if(new_sum >= matrix.size()){
                continue;
            }
            if(new_row == matrix[new_sum]){
                if(is_ambiguous){
                    ambiguous_list.insert(new_sum);
                }
                continue;
            }
            if((visited_sums.find(new_sum) != visited_sums.end()) || is_ambiguous){
                ambiguous_list.insert(new_sum);
            }
            matrix[new_sum] = new_row;
            visited_sums.insert(new_sum);
        }
    }

    for(int item : orders){
        if(impossible_list.find(item) != impossible_list.end()){
            cout << "Impossible" << endl;
            continue;
        }
        if(ambiguous_list.find(item) != ambiguous_list.end()){
            cout << "Ambiguous" << endl;
            continue;
        }

        for(int i = 0; i < matrix[item].size(); i++){
            int q = matrix[item][i];
            if(q > 0){
                for(int w = 0; w < q; ++w){
                    cout << i+1 << ' ';
                }
            }
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