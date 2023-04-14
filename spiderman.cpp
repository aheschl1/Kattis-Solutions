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

typedef vector<vector<int>> vvi;

void solve(){
    const int UP = 1;
    const int DOWN = -1;

    int t; cin >> t;
    while(t--){
      int n; cin >> n;

      vector<int> distances;
      int largest_distance = 0;
      int max_distance = 0;

      for(int i = 0; i < n; i ++){
        int t;
        cin >> t;
        distances.push_back(t);
        max_distance += t;
        if(t > largest_distance){
          largest_distance = t;
        }
      }
      largest_distance += (max_distance + 1);
      vvi positions(n+1, vector<int>(largest_distance, max_distance));
      vvi moves(n+1, vector<int>(largest_distance, 0));
      positions[0][0] = 0;
      for(int pos_at = 0; pos_at < n; pos_at++){
        for(int distance = 0; distance <= max_distance; distance++){
          int current_peak = positions[pos_at][distance];
          //distance if up
          int up = distance + distances[pos_at];
          //distance if down
          int down = distance - distances[pos_at];
          //the next state
          int next_row = pos_at+1;
          //we will now fill in thee next rows informtion i.e. peak at the positions
          if(positions[next_row][up] > max(up, current_peak)){
            positions[next_row][up] = max(up, current_peak);
            //got here by going up
            moves[next_row][up] = UP;
          }
          if((down >= 0) && (positions[next_row][down] > current_peak)){
            positions[next_row][down] = current_peak;
            moves[next_row][down] = DOWN;
          }
        }
      }
      //build ideal path
      if(positions[n][0] == max_distance){
        cout << "IMPOSSIBLE" << endl;
        continue;
      }
      string path = "";
      int distance = 0;
      for(int checking = n; checking > 0; checking--){
        if(moves[checking][distance] == UP){
          distance-=distances[checking-1];
          path = "U" + path;
        }else if(moves[checking][distance] == DOWN){
          distance+=distances[checking-1];
          path = "D" + path;
        }
      }
      cout << path << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}