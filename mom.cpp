#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<string, vector<string>> AL;
unordered_map<string, int> status;
bool back_edge_found;

void dfs(string city) {
  status[city] = 1;
  for (auto &neighbor : AL[city]) {
    if (status[neighbor] == 0)
      dfs(neighbor);
    else if (status[neighbor] == 1) { 
      back_edge_found = true;
    }
  }
  status[city] = 2;
}

int main() {
  int n;
  string origin, destination;
  cin >> n; cin.get();
  while (n--) {
    cin >> origin >> destination;
    AL[origin].push_back(destination);
  }
  while (cin >> origin, !cin.eof()) {
    back_edge_found = false;
    for (auto &city : AL) 
      status[city.first] = 0; 
    dfs(origin);
    cout << origin;
    cout << (back_edge_found ? " safe\n" : " trapped\n");
  }
  return 0;
}