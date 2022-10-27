#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()

int main(){
    int n,q;
    cin >> n >> q;
    vl a(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) c[i] = a[i]-i-1;

    rep(i,q){
        ll ki;
        cin >> ki;
        int r = lower_bound(all(c),ki) - c.begin();
        cout << r + ki << endl;
    }

    return 0;    
}
