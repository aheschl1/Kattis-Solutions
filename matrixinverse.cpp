#include<iostream>

using namespace std;


void finishCalc(int caseNum, int a, int b, int c, int d){
    int first = 1/(a*d - b*c);
    a*=first;
    b*=first;
    c*=first;
    d*=first;
    cout << "Case " << caseNum << ":" << "\n" << d << " " << -b << "\n" << -c << " " << a << endl << endl;
}

int main(){

    int input;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int counter = 0;
    int caseNum = 1;
    
    while(cin >> input){
        switch(counter){
            case 0:
                a = input;
                break;
            case 1:
                b = input;
                break;
            case 2:
                c = input;
                break;
            case 3:
                d = input;
                finishCalc(caseNum, a, b, c, d);
                caseNum ++;
                a = 0;
                b = 0;
                c = 0;
                counter = -1;
                break;
        }
        counter++;
    }



    return 0;
}
