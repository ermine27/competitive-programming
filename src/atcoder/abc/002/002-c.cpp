/*
ヘロンの公式を使って解く
*/
#include <bits/stdc++.h>
using namespace std;


int main(){
    double x1,y1,x2,y2,x3,y3,a,b,c,s,s2;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    a = sqrt( (x3-x2) * (x3-x2) + (y3-y2) * (y3-y2) );
    b = sqrt( (x1-x3) * (x1-x3) + (y1-y3) * (y1-y3) );
    c = sqrt( (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) );

    s2 = (a+b+c)/2;
    s = sqrt(s2*(s2-a)*(s2-b)*(s2-c));

    cout << fixed << s;
    cout << endl;
}
