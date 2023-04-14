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

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

unordered_map<int, int> unionfind;

unordered_map<int, string> code_word;
unordered_map<string, int> word_code;
// Find the root of the set in which element `k` belongs
int find(int k)
{
    if (unionfind[k] == k) {
        return k;
    }
    return unionfind[k] = find(unionfind[k]);
}

// Perform Union of two subsets
void Union(int a, int b)
{
    // find the root of the sets in which elements `x` and `y` belongs
    int x = find(a);
    int y = find(b);
    unionfind[x] = y;
}


void solve(){
    int n, m; cin >> n >> m;
    vector<int> essay;
    unordered_set<string> words;
    for(int i = 0; i < n+2*m; i++){
        unionfind[i] = i;
    }
    while(n--){
        string word; cin >> word;
        if(words.find(word)==words.end()){
            code_word[code_word.size()] = word;
            word_code[word] = code_word.size()-1;
            words.insert(word);
        }
        essay.push_back(word_code[word]);
    }
    while(m--){
        string a, b;
        cin >> a >> b;
        if(words.find(a)==words.end()){
            code_word[code_word.size()] = a;
            word_code[a] = code_word.size()-1;
            words.insert(a);
        }
        if(words.find(b)==words.end()){
            code_word[code_word.size()] = b;
            word_code[b] = code_word.size()-1;
            words.insert(b);
        }
        if(code_word[find(word_code[a])].size() < code_word[find(word_code[b])].size()){
            Union(word_code[b], word_code[a]);
        }else{
            Union(word_code[a], word_code[b]);
        }
    }
    int count= 0;
    for(int word : essay){
        count += code_word[find(word)].size();
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}