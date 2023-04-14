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

int primeFactors(int n) 
{ 
    int count = 0;
    while (n % 2 == 0) 
    { 
        count ++; 
        n = n/2; 
    } 

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    {
        while (n % i == 0) 
        { 
            count ++;
            n = n/i; 
        } 
    } 
    if (n > 2) {
        count ++;
    }
    return count;
}
 

void solve(){
    int n;
    cin >> n;
    cout << primeFactors(n) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}