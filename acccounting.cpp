#include<iostream>
#include<map>
#include<vector>

using namespace std;
typedef long long int lli;

int main(){
    lli numpeople;
    lli commands;
    lli default_val = 0;

    cin >> numpeople;
    cin >> commands;

    map<lli, tuple<bool, lli>> people;

    for(int command = 0; command < commands; command ++){
        string commandtype;
        cin >> commandtype;
        if(commandtype == "SET"){
            lli person, wealth;
            cin >> person >> wealth;
            people[person] = make_tuple(true, wealth);
        }else if(commandtype == "RESTART"){
            cin >> default_val;
            people.clear();
        }else{
            lli person;
            cin >> person;
            try{
                cout << get<1>(people.at(person)) << endl;
            }catch(const out_of_range &e){
                cout << default_val << endl;
            }
        }
    }

    return 0;
}

