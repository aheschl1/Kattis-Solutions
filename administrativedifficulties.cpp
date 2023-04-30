#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>
#include <deque>
#include <unordered_set>
#include <queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct car
{
    int catalog = 0;
    int pickup = 0;
    int km = 0;
};

struct driver
{
    string open_car;
    bool has_car = false;
    int cost = 0;
    bool inconcistent = false;
};

void solve()
{

    int n, events;
    cin >> n >> events;
    unordered_map<string, car> cars;
    map<string, driver> drivers;
    for(int i = 0; i < n; i++){
        string name; cin >> name;
        car &c = cars[name];
        cin >> c.catalog >> c.pickup >> c.km;
    }for (int e = 0; e < events; e++){
        int time;
        string name;
        string event;

        cin >> time;
        cin >> name;
        cin >> event;

        driver &record = drivers[name];

        if (event[0] == 'p'){
            string c;
            cin >> c;
            if (record.has_car || record.inconcistent){
                record.inconcistent = true;
            }else{
                record.open_car = c;
                record.cost += cars[c].pickup;
                record.has_car = true;
            }
        }else if (event[0] == 'r'){
            int km;
            cin >> km;
            if (!record.has_car || record.inconcistent){
                record.inconcistent = true;
            }else
            {
                record.cost += (cars[record.open_car].km * km);
                record.has_car = false;
            }
        }else if (event[0] == 'a'){
            double percent; cin >> percent;
            if (!record.has_car|| record.inconcistent)
            {
                record.inconcistent = true;
            }
            else if(percent > 0)
            {
                record.cost+=(cars[record.open_car].catalog*percent+99)/100;
            }
        }
    }
    for (auto it = drivers.begin(); it != drivers.end(); it++){
        cout << it->first << ' ';
        if (it->second.inconcistent || it->second.has_car)
        {
            cout << "INCONSISTENT" << endl;
        }
        else
        {
            cout << it->second.cost << endl;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}