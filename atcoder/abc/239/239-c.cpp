#include <bits/stdc++.h>
using namespace std;

#define exity(c) if(c){ cout << "Yes"; return 0; }
#define exitn(c) if(c){ cout << "No"; return 0; }


int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int xd = abs(x1 - x2);
    int yd = abs(y1 - y2);

    exity(xd == 1 && yd == 1)
    exity(xd == 0 && yd == 2 || xd == 2 && yd == 0)
    exity(xd == 0 && yd == 4 || xd == 4 && yd == 0)
    exity(xd == 1 && yd == 3 || xd == 3 && yd == 1)
    exity(xd == 3 && yd == 3)
    exity(xd == 2 && yd == 4 || xd == 4 && yd == 2)

    exitn(true);
}
