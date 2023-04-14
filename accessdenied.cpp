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

void solve(){
    int time = 0;
    bool done = false;
    //get length
    int length = 0;
    do{
        length++;
        string temp = "";
        for(int i = 0; i < length; i++){
            temp += "a";
        }
        cout << temp << endl;
        string tr;
        getline(cin, tr);
        if(tr == "ACCESS GRANTED"){
            done = true;
            break;
        }
        time = stoi(tr.substr(15));
    }while(time == 5);
    if(done){
        return;
    }

    //now do letters
    string guess = "";
    for(int i = 0; i < length; i++){
        guess += "A";
    }

    int alphabet_index = 0;
    while(!done){
        cout << guess << endl;

        string tr;
        getline(cin, tr);
        if(tr == "ACCESS GRANTED"){
            break;
        }

        time = stoi(tr.substr(15));
        int letterindex = (time-14)/9;
        if(guess[letterindex] + 1 == 91){
            guess[letterindex] = 97;
        } else if(guess[letterindex] + 1 == 123){
            guess[letterindex] = 48;
        }
        else{
            guess[letterindex]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}