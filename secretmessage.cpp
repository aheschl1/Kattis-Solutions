#include<iostream>
#include<vector>
#include <math.h>

using namespace std;
typedef vector<vector<char>> vvc;

int main(){
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        string encodedm;
        cin >> encodedm;
        int n = sqrt(encodedm.length());
        vvc messages(n, vector<char>(n,' '));

        int index = 0;
        for(int r = 0; r < n; r ++){
            for(int c = 0; c < n; c ++){
                messages[r][c] = encodedm[index];
                index ++;
            }
        }

        vvc decoded(n, vector<char>(n,' '));
        for(int r = 0; r < n; r ++){
            for(int c = 0; c < n; c ++){
                decoded[r][c] = messages[c][r];
            }
        }
        
        for(int r = n-1; r >=0; r --){
            for(int c = 0; c < n; c ++){
                cout << decoded[r][c];
            }
        }
        cout << "\n";
    }

    return 0;
}