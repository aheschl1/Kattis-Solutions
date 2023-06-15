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
#include<queue>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct Interval{
    double right;
    double left;
    int name = -1;
    bool valid = true;
};

bool compare(Interval &a, Interval &b){
    return a.right > b.right;
}

void solve(Interval target){
    int n; cin >> n;
    vector<Interval> intervals;
    int index = 0;
    while(n--){
        Interval t;
        cin >> t.left >> t.right;
        t.name = index++;
        intervals.push_back(t);
    }
    
    sort(intervals.begin(), intervals.end(), compare);

    double max_right = target.left;
    vector<int> used;
    while((max_right < target.right) || (target.right == target.left)){
        bool found = false;
        for(Interval &interval : intervals){
            if(interval.left > max_right || !interval.valid){
                continue;
            }
            if(interval.right < max_right){
                break;
            }
            max_right = interval.right;
            used.push_back(interval.name);
            found = true;
            interval.valid = false;
            break;
        }
        if(!found){
            cout << "impossible" << endl;
            return;
        }
        if(target.left == target.right){
            break;
        }
    }
    cout << used.size() << endl;
    for(int t : used){
        cout << t << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Interval target;
    while(cin >> target.left >> target.right){
        solve(target);
    }
    return 0;
}