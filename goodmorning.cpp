#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<string>


typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void num_list(set<int> &possible, int digit, int current){
    if(current > 200){
        return;
    }
    possible.insert(current);
    if(digit == 1){
        //don't take
        num_list(possible, 2, current);
        num_list(possible, 4, current);
        //take
        num_list(possible, 1, current*10+1);
        num_list(possible, 2, current*10+1);
        num_list(possible, 4, current*10+1);
    }else if(digit == 2){
        //don't take
        num_list(possible, 3, current);
        num_list(possible, 5, current);
        //take
        num_list(possible, 2, current*10+2);
        num_list(possible, 3, current*10+2);
        num_list(possible, 5, current*10+2);
    }else if(digit == 3){
        //don't take
        num_list(possible, 6, current);
        //take
        num_list(possible, 3, current*10+3);
        num_list(possible, 6, current*10+3);
    }else if(digit == 4){
        //don't take
        num_list(possible, 7, current);
        num_list(possible, 5, current);
        //take
        num_list(possible, 7, current*10+4);
        num_list(possible, 5, current*10+4);
        num_list(possible, 4, current*10+4);
    }else if(digit == 5){
        //don't take
        num_list(possible, 6, current);
        num_list(possible, 8, current);
        //take
        num_list(possible, 6, current*10+5);
        num_list(possible, 8, current*10+5);
        num_list(possible, 5, current*10+5);
    }else if(digit == 6){
        //don't take
        num_list(possible, 9, current);
        //take
        num_list(possible, 9, current*10+6);
        num_list(possible, 6, current*10+6);
    }else if(digit == 7){
        //don't take
        num_list(possible, 8, current);
        //take
        num_list(possible, 7, current*10+7);
        num_list(possible, 8, current*10+7);
    }else if(digit == 8){
        //don't take
        num_list(possible, 9, current);
        num_list(possible, 0, current);
        //take
        num_list(possible, 9, current*10+8);
        num_list(possible, 0, current*10+8);
        num_list(possible, 8, current*10+8);
    }else if(digit == 9){
        //don't take
        //take
        num_list(possible, 9, current*10+9);
    }else if (digit == 0){
        //take
        if(current!=0){
            num_list(possible, 0, current*10);
        }
    }
}

void solve(){
    int T; cin >> T;
    set<int> possible;
    num_list(possible, 1, 0);

    vector<int> possible_list(possible.begin(), possible.end());
    sort(possible_list.begin(), possible_list.end());
    while(T--){
        int k; cin >> k;
        int lowest_diff = 300;
        int num = 0;
        for(int i : possible_list){
            if(abs(k-i) < lowest_diff){
                num = i;
                lowest_diff = abs(k-i);
            }
        }
        cout << num << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}