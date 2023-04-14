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

int execute(vector<string> &ram, vector<int> &registers, int i){
    string command = ram[i];
    int type, first, second;
    type = command[0] - 48;
    first = command[1] - 48;
    second = command[2] - 48;
    switch(type){
        case 1:
            return -2;
        case 2:
            registers[first] = second;
            break;
        case 3:
            registers[first] = (registers[first] + second)%1000;
            break;
        case 4:
            registers[first] = (registers[first] * second)%1000;
            break;
        case 5:
            registers[first] = registers[second];
            break;
        case 6:
            registers[first] = (registers[first]+ registers[second])%1000;
            break;
        case 7:
            registers[first] = (registers[first] * registers[second])%1000;
            break;
        case 8:
            registers[first] = stoi(ram[registers[second]]);
            break;
        case 9:
            if(registers[first] < 10){
                ram[registers[second]] = to_string(registers[first]) + "00";
            }else if(registers[first] < 100){
                ram[registers[second]] = to_string(registers[first]) + "0";
            }else{
                ram[registers[second]] = to_string(registers[first]);
            }
            break;
        default:
            if(registers[second] == 0){
                break;
            }
            return registers[first];
    }
    return -1;

}

void solve(){
    vector<string> ram(1000,"000");
    vector<int> registers(10, 000); // 0 through 9
    int count = 0;
    string N;
    int i = 0;
    while(getline(cin, N)){
        ram[i++] = N;
    }
    for(int r = 0; r < 1000; r++){
        begin_l:
        count++;
        int result = execute(ram, registers, r);
        if(result == -1){
            continue;
        }
        if(result == -2){
            break;
        }
        r = result;
        goto begin_l;
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}