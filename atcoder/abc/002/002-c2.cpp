/*

△OAB, A(x1,y1), B(x2,y2), OA = a, OB = b,  とする。

三角形の面積のベクトル表示
　S = 1/2 * √( |x|^2 |y|^2 - (x・y)^2 )
三角形の面積の成分表示（頂点の１つは原点である必要がある）
　S = 1/2 * |x1y2 - x2y1|

*/
#include <bits/stdc++.h>
using namespace std;


int main(){
    double x1,y1,x2,y2,x3,y3,s;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    x2 -= x1; x3 -= x1;
    y2 -= y1; y3 -= y1;

    s = 0.5 * abs(x2*y3 - x3*y2);

    cout << fixed << s;
    cout << endl;
}
