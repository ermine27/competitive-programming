#include <bits/stdc++.h>
using namespace std;

int main(){
    double a,b,r,da,db;
    cin >> a >> b;

    r = sqrt(a*a + b*b);

    da = a * (1.0 / r);
    db = b * (1.0 / r);

    cout << fixed << setprecision(10);
    cout << da << ' ' << db;
}