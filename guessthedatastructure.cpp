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
#include<queue>
#include<stack>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;


void solve(){
    int lines;
    while(cin >> lines){
        priority_queue<int> pq;
        stack<int> s;
        queue<int> q;
        bool pq_p= true; bool s_p = true; bool q_p = true;
        while(lines--){
            int type, val;
            cin>>type>>val;
            if(type == 1){
                pq.push(val);
                s.push(val);
                q.push(val);
            }else{
                if(s.empty() || q.empty() || pq.empty()){
                    pq_p = false;
                    s_p = false;
                    q_p = false;
                }else{
                    int pqv = pq.top(); pq.pop();
                    int stackv = s.top(); s.pop();
                    int qv = q.front(); q.pop();
                    
                    if(pqv != val)pq_p = false;
                    if(stackv != val)s_p = false;
                    if(qv != val)q_p = false;
                }
            }
        }
        if((pq_p + s_p + q_p == 0)){
            cout << "impossible" << endl;
        }else if((pq_p + s_p + q_p) > 1){
            cout << "not sure" << endl;
        }else if(pq_p){
            cout << "priority queue" << endl;
        }else if(q_p){
            cout << "queue" << endl;
        }else{
            cout << "stack" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}