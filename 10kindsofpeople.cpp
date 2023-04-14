#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<stack>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

typedef vector<vector<int>> vvi;

void flood_fill(vvi &zoneslist, int target, int new_color, pair<int, int> location){
    int r = location.first;
    int c = location.second;
    if(zoneslist[r][c] == target){
        zoneslist[r][c] = new_color;
    }else{
        return;
    }

    //above
    if(r > 0){
        flood_fill(zoneslist, target, new_color, make_pair(r-1, c));
    }
    //below
    if(r < zoneslist.size()-1){
        flood_fill(zoneslist, target, new_color, make_pair(r+1, c));
    }
    //left
    if(c > 0){
        flood_fill(zoneslist, target, new_color, make_pair(r, c-1));
    }
    //right
    if(c < zoneslist[0].size()-1){
        flood_fill(zoneslist, target, new_color, make_pair(r, c+1));
    }
}

void display(vvi &zoneslist){
    for(vector<int> vc : zoneslist){
        for(int c : vc){
            cout << c;
        }
        cout << endl;
    }
}

void solve(){
    ll rows, columns;
    cin >> rows >> columns;
    string t;
    getline(cin, t);
    vvi zoneslist(rows, vector(columns, 0));
    for(ll r = 0; r < rows; r++){
        string row;
        getline(cin, row);
        ll c = 0;
        for(char &ch : row){
            zoneslist[r][c] = ch-48;
            c++;
        }
    }
    ll binary_replacement = 2;
    ll decimal_replacement = 3;
    for(int row = 0; row < rows; row ++){
        for(int column = 0; column < columns; column++){
            int current = zoneslist[row][column];
            if(current == 0){
                flood_fill(zoneslist, 0, binary_replacement, make_pair(row, column));
                binary_replacement+=2;
            }else if(current == 1){
                flood_fill(zoneslist, 1, decimal_replacement, make_pair(row, column));
                decimal_replacement+=2;
            }
        }
    }
    ll num_queries;
    cin >> num_queries;
    for(ll i = 0; i < num_queries; i++){
        ll sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        sr--;sc--;er--;ec--;
        if(zoneslist[sr][sc]!=zoneslist[er][ec]){
            cout << "neither" << endl;
        }else if(zoneslist[sr][sc]%2 == 0){
            cout << "binary" << endl;
        }else{
            cout << "decimal" << endl;    
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}