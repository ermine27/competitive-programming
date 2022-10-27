#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;


int main(){
    const ll dmod = 998244353;
    int  n;
    cin >> n;
    --n;
    
    vl nib(9,1),nia(9);
    rep(i,n){
        rep(j,9){
            if(j==0 || j==8){
                nia[j] = nib[0] + nib[1];
            } else {
                nia[j] = nib[j-1] + nib[j] + nib[j+1];
            }
            nia[j] %= dmod;
        }
        nib = nia;

    }

    ll ans = 0;
    rep(i,9){
        ans += nib[i];
        ans %= dmod;
    }
    cout << ans;
}