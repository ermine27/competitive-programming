/*
使うオーブンは2つなので、bitsetを使ってDPをする
dpには1つ目のオーブンを使うか否かだけを持つ
　→bitsetを使うとorだけでDPができる
2つ目のオーブンを使う時間は全ての時間から1つ目のオーブンを使う時間を引いた時間になる

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 2e9;


int main(){
    int n;
    cin >> n;
    bitset<100001> dp;
    dp[0] = 1;
    int s = 0;

    rep(i,n){
        int ti;
        cin >> ti;
        s += ti;
        dp |= dp << ti;
    }

    int ans = s;
    rep(i,s+1){
        if(dp[i]){
            chmin(ans, max(i, s - i));
        }
    }

    cout << ans;
}
