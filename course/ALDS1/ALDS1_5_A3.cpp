/*
bit全探索で解く（その２）

bitsetの代わりにビット演算を使うと実行時間が高速になる。
（bitsetを使った時の4分の1）

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;


int main(){
    int n, q;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    cin >> q;
    vi m(q);
    rep(i,q) cin >> m[i];

    vi h(2001);
    rep(i,1<<n){
        int sum = 0;
        rep(j,n){
            sum += i & (1<<j) ? a[j] : 0;
        }
        if(sum <= 2000){
            h[sum]++;
        }
    }

    rep(i,q) cout << (h[m[i]] ? "yes" : "no") << endl;
    return 0;
}
