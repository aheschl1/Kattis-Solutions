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
#include<stack>

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

struct node{
    ll value;
    int index;
    node *left = nullptr;
};
typedef vector<stack<node*>> vsn;

bool comp(stack<node*> &a, int b){
    //cout << b << endl;
    return a.top()->value < b;
}

vector<int> f(vector<node*> &list){
    vsn in_play;
    for(node *card : list){
        if(in_play.size() == 0){
            stack<node*> t;
            t.push(card);
            in_play.push_back(t);
            continue;
        }
        vsn::iterator target = lower_bound(in_play.begin(), in_play.end(), card->value, comp);
        if(target == in_play.end()){
            card->left = in_play[in_play.size()-1].top();
            stack<node*> t;
            t.push(card);
            in_play.push_back(t);
        }else{
            int left_index = target - in_play.begin() - 1;
            if(left_index >= 0){
                card->left = in_play[left_index].top();
            }
            target->push(card);
        }
        
    }
    vector<int> lis;
    node* current = in_play[in_play.size()-1].top();
    while(current != nullptr){
        lis.push_back(current->index);
        current = current->left;
    }
    return lis;
}

void solve(int n){
    vector<node*> list;
    for(int i = 0; i < n; i++){
        node *t = new node; cin >> t->value;
        t->index = i;
        list.push_back(t);
    }
    vector<int> lis = f(list);
    cout << lis.size() << endl;
    for(int i = lis.size()-1; i >= 0; i--){
        cout << lis[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n){
        solve(n);
    }
    return 0;
}