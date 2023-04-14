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

struct problem{
    bool solved = false;
    int score = 0;
};

void solve(){
  map<char, problem> results;
  int time;
  while(cin>>time){
    if(time == -1){
        break;
    }
    char name;
    string result;
    cin >> name >> result;
    if(results.find(name) == results.end()){
        problem temp;
        results[name] = temp;
    }
    if(result == "right"){
        results[name].score += time;
        results[name].solved = true;
    }else{
        results[name].score += 20;
    }
  }
  int total = 0;
  int solve_count = 0;
  for(pair<char, problem> p : results){
    if(p.second.solved){
        total+=p.second.score;
        solve_count++;
    }
  }
  cout << solve_count << " " << total << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}