#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,d,r;
    double f;
    cin >> a >> b;

    d = a / b;
    r = a % b;
    f = 1.0 * a / b;

    cout << fixed << setprecision(10);
    cout << d << ' ' << r << ' ' << f << endl;
}
