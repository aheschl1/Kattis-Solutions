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

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct score{
    int left;
    int right;
    score(int left = -1, int right = -1){
        this->left = left;
        this->right = right;
    }
};

map<string, bool> memo;

bool works(score current, score &target){
    //cout << current.left << ' ' << current.right << endl;
    string currents = to_string(current.left) + ' ' + to_string(current.right);
    if(max(target.left, target.right) > 11){
        memo[currents] = false;
        return false;
    }
    if(memo.find(currents) != memo.end()){
        return memo[currents];
    }else if(current.left == target.left && current.right == target.right){
        memo[currents] = true;
        return true;
    }else if(current.left == 11 || current.right == 11){
        memo[currents] = false;
        return false;
    }else if((current.left > target.left && current.left > target.right) || (current.right > target.left && current.right > target.right)){
        memo[currents] = false;
        return false;
    }
    bool works_r = false;
    //even switch, odd same
    score t;
    if((current.left + current.right)%2 == 0){
        //right score flip
        t = score(current.right+1, current.left);
        works_r = works_r || works(t, target);
        if(works_r){
            memo[currents] = works_r;
            return works_r;
        }
        //left score flip
        t = score(current.right, current.left+1);
        works_r = works_r || works(t, target);
        if(works_r){
            memo[currents] = works_r;
            return works_r;
        }
    }else{
        //left score no flip
        t = score(current.left+1, current.right);
        works_r = works_r || works(t, target);
        if(works_r){
            memo[currents] = works_r;
            return works_r;
        }
        //right score no flip
        t = score(current.left, current.right+1);
        works_r = works_r || works(t, target);
        if(works_r){
            memo[currents] = works_r;
            return works_r;
        }
    }
    memo[currents] = works_r;
    return works_r;
}

void solve(){
    int lines;
    cin >> lines;
    score a(0 , 0);
    bool ok = true;
    int line = 0;
    while(lines--){
        line ++;
        int l, r;
        cin >> l; cin.ignore(); cin >> r;
        
        score b = score(l, r);
        bool atob = works(a, b);
        memo.clear();
        if(!atob){
            ok = false;
            //cout << a.left << ' ' << a.right << endl;
            //cout << b.left << ' ' << b.right << endl;
            break;
        }
        a = b;
        
    }
    if(ok){
        cout << "ok" << endl;
    }else{
        cout << "error " << line << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}