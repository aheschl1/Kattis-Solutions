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
typedef vector<vector<int>> vvi;

void flood(vvi &webpage, int r, int c, int boundary){
    int ch = webpage[r][c];
    webpage[r][c] = '_';
    if(ch == boundary || ch=='_'){
        return;
    }
    
    //above
    if(r > 0){
        flood(webpage, r-1, c, boundary);
    }
    //below
    if(r < webpage.size()-1){
        flood(webpage, r+1, c, boundary);
    }
    //left
    if(c > 0){
        flood(webpage, r, c-1, boundary);
    }
    //right
    if(c < webpage[0].size()-1){
        flood(webpage,r, c+1, boundary);
    }
    
    //top left
    if(r > 0 && c > 0){
        flood(webpage, r-1, c-1, boundary);
    }
    //top right
    if(r > 0 && c < webpage[0].size()-1){
        flood(webpage,r-1, c+1, boundary);
    }
    //bottom left
    if(r < webpage.size()-1 && c > 0){
        flood(webpage, r+1, c-1, boundary);
    }
    //bottom right
    if(r < webpage.size()-1 && c < webpage[0].size()-1){
        flood(webpage, r+1, c+1, boundary);
    }
}

void flood_proper(vvi &webpage, int replacement, int r, int c){
    int ch = webpage[r][c];
    if(ch != '+' || ch == replacement){
        return;
    }
    webpage[r][c] = replacement;
    
    //above
    if(r > 0){
        flood_proper(webpage, replacement, r-1, c);
    }
    //below
    if(r < webpage.size()-1){
        flood_proper(webpage,replacement,  r+1, c);
    }
    //left
    if(c > 0){
        flood_proper(webpage, replacement, r, c-1);
    }
    //right
    if(c < webpage[0].size()-1){
        flood_proper(webpage,replacement, r, c+1);
    }
}

pair<int, int> determine_boudary(vvi &webpage, int r, int c){
    set<int> above;
    for(int row = r; row >= 0; row--){
        if(webpage[row][c] < 32){
            above.insert(webpage[row][c]);
        }
    }
    for(int row = r; row < webpage.size(); row++){
        if(webpage[row][c] < 32){
            if(above.find(webpage[row][c]) != above.end()){
                return make_pair(true, webpage[row][c]);
            }
        }
    }
    return make_pair(-10000000, 0);
}

bool legal(int c){
    return c < 32 || (c == '_' || c == ' ' || c == '?' || c=='!' || c == ',' || c == '.' || c == '+' || (c >= 48 && c <=57) || (c >= 65 && c <=90) || (c >= 97 && c <= 122));
}

void display(vvi &webpage){
    for(vector<int> row : webpage){
        for(int c : row){
            cout << (char)c;
        }
        cout << endl;
    }
}

void solve(){
    int rows, columns;
    cin >> rows >> columns;
    cin.ignore();
    vvi webpage;
    for(int r = 0; r < rows; r++){
        vector<int> row;
        string line;
        getline(cin, line);
        for(int c : line){
            if(c == '_'){
                c='#';
            }
            row.push_back(c);
        }
        webpage.push_back(row);
    }
    
    int replacement=31;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            int ch = webpage[r][c];
            if(ch=='+'){
                flood_proper(webpage, replacement, r, c);
                replacement-=1;
            }
        }
    }
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            int ch = webpage[r][c];
            if(!legal(ch)){
                pair<int, int> boundary_type = determine_boudary(webpage, r, c);
                if(boundary_type.first == -10000000){
                    //main image
                    continue;
                }else{
                    flood(webpage, r, c, boundary_type.second);
                }
            }
        }
    }

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            if(webpage[r][c] == '_'){
                webpage[r][c] = ' ';
            }
            if(webpage[r][c] < 32){
                webpage[r][c] = '+';
            }
        }
    }

    display(webpage);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}