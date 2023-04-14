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

ll overlap(vector<pair<double, double> > &v)
{
    ll ans = 0;
    ll count = 0;
    vector<pair<double, char>> data;
 
    for (ll i = 0; i < v.size(); i++) {
        data.push_back(make_pair(v[i].first, 'a' ));
        data.push_back(make_pair(v[i].second, 'z' ));
    }
    sort(data.begin(), data.end());
 
    for (int i = 0; i < data.size(); i++) {

        if (data[i].second == 'a'){
            count++;
        }else{
            count--;
        }
        ans = max(ans, count);

    }
 
    return ans;
}

void solve(){
    double A, B, T, tech_slope, bus_slope, C;
    cin >> A >> B >> T >> tech_slope >> bus_slope >> C;
    //          <=d  >=d        d = time spent on tech. time spent on business = T-d
    vector<pair<double, double>> bounds;
    double no_time_ans = 0;
    while(C--){
        double t, b;
        cin >> t >> b;
        if(t <= A && b <= B){
            no_time_ans+=1;
        }
        double lower_bound = (t-A)*tech_slope;
        double upper_bound = T - (b-B)*bus_slope;
        if(lower_bound <= upper_bound){
            bounds.push_back(make_pair(lower_bound, upper_bound));
        }
    }

    if(T == 0){
        cout << no_time_ans << endl;
        return;
    }
    ll overlap_ans =  overlap(bounds);
    cout << overlap_ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}