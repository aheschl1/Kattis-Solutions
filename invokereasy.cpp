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
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a*c)/(pow(c, 2)+pow(d, 2))) + ((b*d)/((pow(c, 2)+pow(d, 2)))) << " " << -((a*d)/(pow(c, 2)+pow(d, 2))) + ((b*c)/((pow(c, 2)+pow(d, 2)))) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}