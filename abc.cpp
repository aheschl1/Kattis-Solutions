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
    int num;
    int c = 3;
    vector<int> nums;
    vector<char> letts;
    while(c--){
        cin >> num;
        nums.push_back(num);
    }
    string t;
    getline(cin, t);
    c = 3;
    while(c--){
        char t = cin.get();
        letts.push_back(t);
    }
    sort(nums.begin(), nums.end());
    for(char ch : letts){
        if(ch == 'A'){
            cout << nums[0] << " ";
        }else if(ch == 'B'){
            cout << nums[1] << " ";
        }else{
             cout << nums[2] << " ";           
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}