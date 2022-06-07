#include <bits/stdc++.h>
using namespace std;

int main(){
    double x1,y1,x2,y2,ans;
    cin >> x1 >> y1 >> x2 >> y2;
    ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    cout << fixed << ans << endl;
}
