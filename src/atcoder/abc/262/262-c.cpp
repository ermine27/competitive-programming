#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

int main(){
    int n;
    cin >> n;
    vl a(n+1);

    ll same = 0, rev = 0;
    repf(i, n) cin >> a[i];

    repf(i,n){
        if(a[i] == i) ++same;
        else if(a[a[i]] == i) ++rev;
    }

    ll ans = same * (same-1) / 2 + rev / 2;
    cout << ans << endl;
    return 0;
}
