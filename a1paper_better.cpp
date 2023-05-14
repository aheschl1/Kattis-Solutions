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
#include<iomanip>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

unordered_map<int, double> long_edges;

double get_long_edge(int size){
    double length;
    if(long_edges.find(size) != long_edges.end()){
        return long_edges[size];
    }
    if(size == 2){
        return 1.0/(pow(2, 3.0/4.0));
    }else if(size == 3){
        return 1.0/(pow(2, 5.0/4.0));
    }
    length = get_long_edge(size - 2)/2;
    long_edges[size] = length;
    return length;
}

void solve(){
    int n; cin >> n;

    int required = 2;
    double used = 0;

    for(int a = 2; a <= n; a++){
        int quantity; cin >> quantity;
        int tape = ceil(required/2);

        used += tape*get_long_edge(a);
        required -= quantity;
        if(required <= 0){
            break;
        }else{
            required *= 2;
        }
    }

    if(required <= 0){
        cout << setprecision(12) << used << endl;
    }else{
        cout << "impossible" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}