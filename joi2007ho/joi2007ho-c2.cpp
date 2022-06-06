/*
柱の情報を配列ではなくハッシュテーブルを使う。
配列と違って境界判定がいらなくなる。
実行速度は配列に比べるとかなり遅い（unordered_setは使えない）
*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define mp make_pair
using vi = vector<int>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }


const int CMAX = 5000;

int main(){
    int n;
    cin >> n;
    int ans = 0;

    vi x(CMAX), y(CMAX);
    set<pii> c;

    rep(i,n){
        cin >> x[i] >> y[i];
        c.insert(mp(x[i], y[i]));
    }

    rep(i,n){
        rep(j,n){
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];

            int x3 = x[j] - dy;
            int y3 = y[j] + dx;
            int x4 = x[i] - dy;
            int y4 = y[i] + dx;

            if(c.count(mp(x3,y3)) && c.count(mp(x4,y4))){
                int s = dx*dx + dy*dy;
                chmax(ans, s);
            }
        }
    }
    cout << ans << endl;
}
