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

enum ObjectType{CIRCLE, SQUARE};
struct object{
    ObjectType type;
    double size;
    object(ObjectType type, double size){
        this->size = size;
        this->type = type;
    }
};

bool compare(object a, object b){
    if(a.type == b.type){
        return (a.size > b.size);
    }else if(a.type == CIRCLE){
        bool other_fit_in_cylinder = pow(2*pow(b.size, 2), 0.5) < 2*a.size;
        return other_fit_in_cylinder;
    }else{
        bool other_fit_in_cylinder = pow(2*pow(a.size, 2), 0.5) > 2*b.size;
        return other_fit_in_cylinder;
    }
}

void solve(){
    int n;cin>>n;
    vector<object> list;
    while(n--){
        string t;cin>>t;
        int size;cin>>size;
        object o(t=="cylinder"?CIRCLE : SQUARE, size);
        list.push_back(o);
    }
    //largest to smallest.
    sort(list.begin(), list.end(), compare);
    // for(object a : list){
    //     cout << (a.type == CIRCLE ? "cylinder " : "cube ")<< a.size << ", ";
    // }
    // cout << endl;
    //legality check
    bool works = true;
    for(int i = 0; i < list.size()-1; i++){
        object &first = list[i];
        object &second = list[i+1];
        if(first.type == second.type){
            works = (first.size >= second.size);
            if(!works){
                break;
            }
        }else if(first.type == CIRCLE){
            works = pow(2*pow(second.size, 2), 0.5) <= 2*first.size;
            if(!works){
                break;
            }
        }else{
            works = second.size <= first.size/2;
            if(!works){
                break;
            }
        }
    }
    if(!works){
        cout << "impossible" << endl;
    }else{
        for(int i = list.size()-1; i >= 0; i--){
            object &a = list[i];
            cout << (a.type == CIRCLE ? "cylinder " : "cube ") << a.size <<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}