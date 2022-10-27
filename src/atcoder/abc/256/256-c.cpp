#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)

const int MAXV = 30;

int main(){
    int h1,h2,h3,w1,w2,w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    int ans = 0;
    repf(p11,MAXV){
        repf(p12,MAXV){
            repf(p21,MAXV){
                repf(p22,MAXV){
                    int p13 = h1 - p11 - p12;
                    int p23 = h2 - p21 - p22;
                    int p31 = w1 - p11 - p21;
                    int p32 = w2 - p12 - p22;
                    int p33h = h3 - p31 - p32;
                    int p33w = w3 - p13 - p23;
                    if(p13 > 0 && p23 > 0 && p31 > 0 && p32 > 0 && p33h > 0 && p33h == p33w){
                        ++ans;
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
