#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
    int r,c;
    vvi a(2, vi(2));
    cin >> r >> c;
    rep(i,2) rep(j,2) cin >> a[i][j];

    cout << a[r-1][c-1];
    return 0;
}
