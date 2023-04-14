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
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
    int max_mess = 0;
    int num_days, visits;
    cin >> num_days >> visits;
    //                      mess clean
    unordered_map<int, pair<int,int>> day_map;
    deque<int> visit_days;
    vector<int> cleaning_capability;
    //read days
    for(int d = 0; d < num_days; d++){
        int next_day_mess; cin >> next_day_mess;
        int next_day_clean; cin >> next_day_clean;
        max_mess+=next_day_mess;
        day_map[d+1]=make_pair(next_day_mess, next_day_clean);
        cleaning_capability.push_back(0);
        for(int i = 0; i < cleaning_capability.size(); i++){
            cleaning_capability[i] += next_day_clean;
        }
    }

    int MAX_CLEANING = num_days+1;
    
    while(visits --){
        int t; cin >> t;
        visit_days.push_back(t);
        //first ............. last
    }

    if(max_mess == 0){
        cout << "0" << endl;
        return;
    }

    vector<int> current_day_vector(max_mess+1, MAX_CLEANING);
    current_day_vector[0] = 0;

    for(int day = 0; day < num_days; day++){
        vector<int> next_day_vector(max_mess+1, MAX_CLEANING);
        pair<int,int> daydata = day_map[day+1];
        int next_day_mess = daydata.first;
        int next_day_clean = daydata.second;

        bool is_visit_day = false;
        if(day == visit_days[0]){
            // we need to be clean this day. only update based on mess 0. Also, if current_best is max, then impossible.
            is_visit_day = true;
        }
        for(int mess = 0; mess <= max_mess && mess <= cleaning_capability[day]; mess++){

            int current_best = current_day_vector[mess];
            if(is_visit_day){
                if(current_best == MAX_CLEANING){
                    cout << "-1" << endl;
                    return;
                }
                if(visit_days.size() == 1){
                    //last visit day. print the current best. return
                    cout << current_best << endl;
                    return;
                }

            }
            if(current_best == MAX_CLEANING){
                //never got here
                continue;
            }

            //clean
            int mess_tmrw_with_clean = (next_day_mess+mess)-next_day_clean;
            mess_tmrw_with_clean = mess_tmrw_with_clean > 0 ? mess_tmrw_with_clean : 0;
            if(mess_tmrw_with_clean < (max_mess+1)){
                if(next_day_vector[mess_tmrw_with_clean] > (current_best+1)){
                    next_day_vector[mess_tmrw_with_clean] = (current_best+1);
                }
            }
            
            //don't clean
            if((next_day_mess + mess) < (max_mess+1)){
                if(next_day_vector[next_day_mess+mess] > (current_best)){
                    next_day_vector[next_day_mess+mess] = current_best;
                }   
            }
        
            if(is_visit_day){
                // only mess = 0 gives a solution
                break;
            }
        }
        current_day_vector=next_day_vector;
        if(is_visit_day){
            visit_days.pop_front();
        }
    }
    //didnt reach the last visit (last day)
    if(current_day_vector[0] == MAX_CLEANING){
        cout << "-1" << endl;
        return;
    }
    cout << current_day_vector[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}