#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;


int main(){
    int r,c;
    vi a(4);
    cin >> r >> c;
    rep(i,4) cin >> a[i];

    int w = 0;
    if(r == 2) w += 2;
    if(c == 2) w += 1;

    cout << a[w];
    return 0;
}
