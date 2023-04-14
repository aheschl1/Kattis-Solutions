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
    int N, t;
    cin >> N >> t;
    vector<int> A;
    set<int> Aset;

    bool duplicates = false;
    map<int, int> occurance;
    int reocurring = -1;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        if(Aset.find(temp) != Aset.end()){
            duplicates = true;
        }
        occurance[temp]++;
        if(occurance[temp] > (N/2)){
            reocurring = temp;
        }
        A.push_back(temp);
        Aset.insert(temp);
    }
    if(t==1){
        for(int x : A){
            if(Aset.find(7777-x)!=Aset.end()){
                cout << "Yes" << endl;
                return;
            }
        }
        cout << "No" << endl;
    }else if(t==2){
        if(duplicates){
            cout << "Contains duplicate" << endl;
        }else{
            cout << "Unique" << endl;
        }
    }else if(t==3){
        cout << reocurring << endl;
    }
    sort(A.begin(), A.end());
    if(t==4){
        if(N%2){
            //odd
            cout << A[(A.size()-1)/2] << endl;
        }else{
            //even
            cout << A[floor((A.size()-1)/2)] << " " <<  A[floor((A.size()-1)/2)+1] << endl;
        }
    }else if(t==5){
        for(int x : A){
            if(x >= 100 && x <= 999){
                cout << x << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}