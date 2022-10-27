// bitsetを使わないで、int値でbit全探索をする
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 2e9;
const long long INFLL = 1e18;


int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    int ans = INF;

    rep(bit, 1 << (n-1)){
        int vor = 0;
        int vxor = 0;
        rep(i,n){
            vor |= a[i];
            if(i < n-1 && bit >> i & 1){
                vxor ^= vor;
                vor = 0;
            }
        }
        vxor ^= vor;

        chmin(ans, vxor);
    }

    cout << ans;
}
