#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    int h, w, s1x = -1, s1y, s2x, s2y;
    cin >> h >> w;

    rep(i,h) rep(j,w){
        char c;
        cin >> c;
        if(c == 'o'){
            if(s1x == -1){
                s1x = i;
                s1y = j;
            } else {
                s2x = i;
                s2y = j;
            }
        }
    }

    cout << abs(s1x - s2x) + abs(s1y - s2y);
}
