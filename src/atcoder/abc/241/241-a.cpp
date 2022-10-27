#include <bits/stdc++.h>
using namespace std;
#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;

int main(){
    vi a(10);
    rep(i,10) cin >> a[i];

    int ans = 0;
    rep(i,3)  ans = a[ans];

    cout << ans;
}
