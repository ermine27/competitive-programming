/*
TLE

bit全探索の処理は、2^20 = 1048576 --> 10^6 として、
各miの判定ごとに実行すると10^6 * 200 --> 10^8 で計算時間が長すぎてTLEしてしまう

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);
#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;

int main(){
    fastio

    int n, q;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    cin >> q;
    vi m(q);
    rep(i,q) cin >> m[i];

    rep(i,q){
        bool ok = false;
        rep(j,1<<n){
            bitset<20> bs = j;

            int sum = 0;
            rep(k,n){
                sum += bs[k] ? a[k] : 0;
                if(sum > m[i]) break;
            }
            if(sum == m[i]){
                ok = true;
                break;
            }
        }

        cout << (ok ? "yes" : "no") << endl;
    }
}
