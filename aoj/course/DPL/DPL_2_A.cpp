/*
巡回セールスマン問題
bit DP

参考
https://algo-logic.info/bit-dp/
https://qiita.com/Ll_e_ki/items/fa475f5bb224ada9be97
*/

#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int INF = 1e9;

int main(){
    int v, e;
    in(v, e);
    vvis(g,v,v,INF);
    rep(i,e){
        int s,t,d;
        in(s,t,d);
        g[s][t] = d;
    }

    vvis(dp,1<<v,v,INF);

    // スタートを頂点 0 とする
    dp[0][0] = 0;

    // s: 集合をbitで表す
    rep(s, 1<<v){
        // to: 配られる側の要素
        rep(to,v){
            // from: 配る側の要素
            rep(from,v){
                // from番目の頂点に訪れていない場合は処理をしない（fromから配れない）
                if(s != 0 && !(s & (1<<from))) continue;

                // to番目の頂点にまだ訪れていない場合にDPの更新をする
                if((s&(1<<to)) == 0){
                    if(to != from){
                        chmin(dp[s | (1<<to)][to], dp[s][from] + g[from][to]);
                    }
                }
            }
        }
    }

    // 0番目の値が答えになる（=0番目の頂点に到達した時）
    int ans = dp[(1<<v)-1][0];
    if(ans == INF) ans = -1;
    out(ans);

    return 0;
}
