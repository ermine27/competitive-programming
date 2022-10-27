#include <bits/stdc++.h>
using namespace std;

int main(){
    double r,l,s,pi = 3.141592653589;
    cin >> r;
    
    s = r * r * pi;
    l = 2 * r * pi;

    cout << fixed << setprecision(10);
    cout << s << ' ' << l << endl;
}
