#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;


int main(){
    ll n, ans = 0;
    cin >> n;

    int ns = to_string(n).length();
    rep(i, (ns-1) / 3) ans += n - (pow(1000,i+1) - 1);

    cout << ans;
}