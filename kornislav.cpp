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

void solve(){
    vector<int> nums;
    for(int i = 0; i < 4; i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());
    cout << nums[0]*nums[2] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}