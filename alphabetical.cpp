#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool is_alphabetical(vector<string> list, int size){
    unsigned char last = 0;
    for(int i = 0; i < size; i++){
        if(list[i][0] > last){
            last = list[i][0];
        }else if(list[i][0] < last){
            return false;
        }else{
            int x = 1;
            while(list[i][x] == list[i-1][x]){
                x++;
            }
            if(list[i][x] < list[i-1][x]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    unsigned int length;
    cin >> length;

    vector<string> list;

    for(int i = 0; i < length; i++){
        string temp;
        cin >> temp;

        list.push_back(temp);
    }
    bool a = is_alphabetical(list, list.size());
    if(!a){
        reverse(list.begin(), list.end());
        bool ra = is_alphabetical(list, list.size());
        if(!ra){
            cout << "NEITHER" << endl;
        }else{
            cout << "DECREASING" << endl;
        }
    }else{
        cout << "INCREASING" << endl;
    }
    
    return 0;
}