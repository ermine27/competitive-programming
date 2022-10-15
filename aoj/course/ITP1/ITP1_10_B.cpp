/*
三角形の２辺a,b とその間の角Cとする。
　aを底辺とした時の高さ h = b * sinC
　面積 S = 1/2 * a * h = 1/2 * a * b * sinC
　辺cの長さ c =  √（a^2 + b^2 - 2*a*b*cosC）　←余弦定理より
　周りの長さ L = a + b + c = a + b +  √（a^2 + b^2 - 2*a*b*cosC）
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c,s,l,h,rad;
    cin >> a >> b >> c;
    rad = c * M_PI / 180;

    s = a * b * sin(rad) / 2;
    l = sqrt(a*a + b*b - 2*a*b*cos(rad)) + a + b;
    h = b * sin(rad);

    cout << fixed << setprecision(10);
    cout << s << endl;
    cout << l << endl;
    cout << h << endl;
}
