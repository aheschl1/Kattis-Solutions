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
    int r;
    cin >> r;
    while(r--){
        double xa,ya,za,ra,vax,vay,vaz,xb,yb,zb,rb,vbx,vby,vbz;
        cin >> xa >> ya >> za >> ra >> vax >> vay >> vaz >> xb >> yb >> zb >> rb >> vbx >> vby >> vbz;
        double px, py, pz;
        px = (xa - xb);
        py = (ya - yb);
        pz = (za - zb);
        double sx, sy, sz;
        sx = (vax - vbx);
        sy = (vay - vby);
        sz = (vaz - vbz);
        double e = (sx*px + sy*py + sz*pz)*2;
        double d = (sx*sx + sy*sy + sz*sz);
        double f = (px*px + py*py + pz*pz) - ((ra + rb)*(ra + rb));
        double discriminant = (e*e - (4*d*f));
        if(discriminant < 0 || (2*d) == 0){
            cout << "No collision" << endl;
            continue;
        }
        double result = 0;
        result = -1*e;
        result -= sqrt(discriminant);
        result/=(2*d);
        if(result < 0){
            cout << "No collision" << endl;
            continue;
        }
        cout << result << endl;

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}