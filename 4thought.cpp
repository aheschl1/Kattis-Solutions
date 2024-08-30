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

typedef long long int ll;
typedef unsigned long long ull;

using namespace std;

/**
 * This was orignally implmented to be generalizable to any set of operation.
 * But then I hardcoded 3 and 4 :)
 */
int operate(int *operands, char *operators){
    // 3 operators
    for(int i = 0; i < 3; i += 1){
        char op = operators[i];
        if(op == '*' || op == '/'){
            int new_operand = op =='*' ? operands[i] * operands[i+1] : operands[i] / operands[i+1];

            operands[i] = new_operand;
            operands[i+1] = new_operand;
            operators[i] = 'n';
            int o = 1;
            while(i-o >= 0 && operators[i-o]=='n'){
                operands[i-o] = new_operand;
                o+=1;
            }
            o = 1;
            while(i+o <= 2 && operators[i+o]=='n'){
                operands[i+o+1] = new_operand;
                o+=1;
            }
        }
    }
    for(int i = 0; i < 3; i += 1){
        char op = *(operators + i);
        if(op!='n'){
            int new_operand = op =='+' ? operands[i] + operands[i+1] : operands[i] - operands[i+1];
            operands[i] = new_operand;
            operands[i+1] = new_operand;
            operators[i] = 'n';
            int o = 1;
            while(i-o >= 0 && operators[i-o]=='n'){
                operands[i-o] = new_operand;
                o+=1;
            }
            o = 1;
            while(i+o <=2 && operators[i+o]=='n'){
                operands[i+o+1] = new_operand;
                o+=1;
            }
        }
    }
    return *(operands);
}

void solve(){
    char operators[] = {'-', '+', '/', '*'};
    unordered_map<int, char*> solutions;

    for(int i = 0; i<4; i+=1){
        for(int n = 0; n<4; n+=1){
            for(int z = 0; z<4; z+=1){
                char *ops = new char[3];
                char *sol = new char[3];

                int operands[] = {4, 4, 4, 4};

                ops[0] = operators[i];
                sol[0] = operators[i];

                ops[1] = operators[n];
                sol[1] = operators[n];
                
                ops[2] = operators[z];
                sol[2] = operators[z];

                int s = operate(operands, ops);
                // solution->append(" = " + (char)(s-'0'));
                solutions[s] = sol;
            }
        }
    }
    int i; cin>>i;
    while(cin >> i){
        if(solutions.find(i) == solutions.end()){
            cout << "no solution" << endl;
        }else{
            char * sol = solutions[i];
            cout << 4 << " " << *(sol) << " " << 4 << " " << *(sol+1) << " " << 4 << " " << *(sol+2) << " " << 4 << " = " << i << endl;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}