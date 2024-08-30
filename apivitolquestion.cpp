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

void solve(){
    int n; cin >> n;
    vector<int> arr;
    for(int _ = 0; _ < n; _++){
        int i; cin >> i;
        arr.push_back(i);
    }
    // build "max up to" list
    vector<int> max_up_to;
    for(int i = 0; i < n; i++){
        if(i==0 || arr[i] > max_up_to[i-1]){
            max_up_to.push_back(arr[i]);
        }else{
            max_up_to.push_back(max_up_to[i-1]);
        }
    }
    // build 'min up to' list
    vector<int> min_up_to(n, INT32_MAX);
    // for(int i : min_up_to){
    //     cout << i << ' ';
    // }
    // cout << endl;
    for(int i = n-1; i >= 0; i--){
        if(i==n-1 || arr[i] < min_up_to[i+1]){
            min_up_to[i] = arr[i];
        }else{
            min_up_to[i] = min_up_to[i+1];
        }
    }

    vector<int> solutions;
    for(int pidx = 0; pidx < arr.size(); pidx+=1){
        bool pass = false;
        if(max_up_to[pidx] <= arr[pidx]){
            pass = true;
        }
        // if(!(pidx == arr.size()-1 || min_up_to[arr.size()-1] > arr[pidx])){
        //     pass = false;
        // }
        if(pidx < arr.size()-1){
            if(min_up_to[pidx+1] <= arr[pidx]){
                pass = false;
        }
        }
        if(pass)
            solutions.push_back(arr[pidx]);
    }

    cout << solutions.size();
    int w = solutions.size();
    if(w > 100){
        w = 100;
    }
    for(int i = 0; i < w; i++){
        cout << ' ';
        cout << solutions[i];
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}