#include <bits/stdc++.h>
using namespace std;

int main(){
    int xx1,xx2,xx3,yy1,yy2,yy3, ansx,ansy;
    cin >> xx1 >> yy1 >> xx2 >> yy2 >> xx3 >> yy3;

    if(xx1 == xx2) ansx = xx3;
    if(xx2 == xx3) ansx = xx1;
    if(xx3 == xx1) ansx = xx2;

    if(yy1 == yy2) ansy = yy3;
    if(yy2 == yy3) ansy = yy1;
    if(yy3 == yy1) ansy = yy2;

    cout << ansx << ' ' << ansy;
}