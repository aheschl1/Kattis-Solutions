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
    string bases = "123456789abcdefghijklmnopqrstuvwxyz0";
    int N; cin >> N;
    while(N--){
        string a, operation, b, t, result; cin >> a >> operation >> b >> t >> result;
        vector<char> valid;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(result.begin(), result.end());
        for(int base = 1; base <= 36; base++){

            double a_decimal = 0, b_decimal = 0, result_decimal = 0;
            bool kill = false;
            for(int i = 0; i < a.size(); i++){
                int c = (int)a[i];
                int value;
                if(c >= 48 && c <= 57){value = c-48;}else{value = c-87;}
                if(base == 1){
                    if(value != 1){
                        kill = true;
                        break;
                    }
                }else if(value >= base){
                    kill = true;
                    break;
                }
                a_decimal += value*pow(base,i);
            }
            for(int i = 0; i < b.size(); i++){
                char c =  (int)b[i];
                int value;
                if(c >= 48 && c <= 57){value = c-48;}else{value = c-87;}
                if(base == 1){
                    if(value != 1){
                        kill = true;
                        break;
                    }
                }else if(value >= base){
                    kill = true;
                    break;
                }
                b_decimal += value*pow(base,i);
            }
            for(int i = 0; i < result.size(); i++){
                char c =  (int)result[i];
                int value;
                if(c >= 48 && c <= 57){value = c-48;}else{value = c-87;}
                if(base == 1){
                    if(value != 1){
                        kill = true;
                        break;
                    }
                }else if(value >= base){
                    kill = true;
                    break;
                }
                result_decimal += value*pow(base,i);
            }

            if(kill){
                continue;
            }

            bool works = false;
            if(operation == "+"){
                works = ((a_decimal + b_decimal) == result_decimal);
            }else if(operation == "-"){
                works = ((a_decimal - b_decimal) == result_decimal);
            }else if(operation == "*"){
                works = ((a_decimal * b_decimal) == result_decimal);
            }else if(operation == "/"){
                works = ((a_decimal / b_decimal) == result_decimal);  
            }
            if(works){
                valid.push_back(bases[base-1]);
            }
        }
        if(valid.size() == 0){
            cout << "invalid" << endl;
        }else{
            for(char base : valid){
                cout << base;
            }
            cout << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}