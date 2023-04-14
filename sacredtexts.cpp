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


char string_to_alph(string s, int offset){
    int score = 0;
    for(char c : s){
        score += c-'!'+1;
    }

    int out = 'a' - offset - 1 + score;
    if(out < 'a'){
        out += 26;
    }else if(out > 'z'){
        out -= 26;
    }       
    return (char)out;
}

vector<string> split(const string& data, const string& delimiters) {
    auto is_delim = [&](auto & c) { return delimiters.find(c) != std::string::npos; };
    std::vector< std::string > result;
    for (std::string::size_type i(0), len(data.length()), pos(0); i <= len; i++) {
        if (is_delim(data[i]) || i == len) {
            auto tok = data.substr(pos, i - pos);
            if ( !tok.empty() )
                result.push_back( tok );
            pos = i + 1;
        }
    } return result;
}

void solve(){
    
    char coresponds;
    string ruin_set;
    cin >> ruin_set;
    cin >> coresponds;

    int sum = 0;
    for(char c : ruin_set){
        sum += c-'!'+1;
    }

    int offset = sum - (coresponds-97+1);

    string line;
    string output;
    getline(cin, output);
    output = "";
    while(getline(cin, line)){

        vector<string> ruins = split(line, " ");
        for(string ruin : ruins){
            if(ruin[0] == '<'){
                output += ',';
            }else if(ruin[0] == '>'){
                output += '.';
            }else if(ruin == "0"){
                output += ' ';
            }else{
                output += string_to_alph(ruin, offset);
            }
        }
        cout << output << endl;
        output = "";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}