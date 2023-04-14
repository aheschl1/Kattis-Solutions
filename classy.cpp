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

struct person{
    string content;
    string name;
    person(string name, vector<char> class_def){
        string s = "";
        if(class_def.size() < 10){
            int diff = (10-class_def.size());
            for(int i = 0; i < diff;i++){
                s = 'b' + s;
            }
        }
        for(char c : class_def){
            s = c + s;
        }
        this->content = s+name;
        this->name = name;
    }
};

bool compare(person &first, person&second){
    return first.content < second.content;
}

void solve(){
    int N;
    cin >> N;
    while(N--){
        int num_p;
        cin >> num_p;

        vector<person> people;
        string t;
        getline(cin , t);
        while(num_p--){
            string name;
            vector<char> class_def;
            char c;
            while((c = cin.get())){
                if(c == ':'){
                    cin.ignore(1);
                    break;
                }
                name += c;
            }
            while((c=cin.get())){
                if(c == 'u'){
                    class_def.push_back('a');
                    cin.ignore(5);
                }else if(c == 'm'){
                    class_def.push_back('b');
                    cin.ignore(6);
                }else if(c == 'l'){
                    class_def.push_back('c');
                    cin.ignore(5);
                }else if(c==' ' || c=='c'){
                    string t;
                    getline(cin, t);
                    break;
                }
            }
            person new_person(name, class_def);
            people.push_back(new_person); 
        }
        std::sort(people.begin(), people.end(), compare);
        for(person p : people){
            cout << p.name << endl;
        }
        cout << "==============================" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}