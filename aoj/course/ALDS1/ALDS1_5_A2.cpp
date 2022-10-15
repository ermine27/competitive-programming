/*
bit全探索で解く

bit全探索の処理は、2^20 = 1048575 --> 10^6 と多いので、
先に全てのパターンで出来る数値を求めておく。
その配列を使って、mが作れるかを判定していく。

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
        bitset<20> bs = i;
        int sum = 0;
        rep(j,n){
            sum += bs[j] ? a[j] : 0;
        }
        if(sum <= 2000){
            h[sum]++;
        }
    }

    rep(i,q) cout << (h[m[i]] ? "yes" : "no") << endl;
    return 0;
}
