/*
2つの点p1(x1,y1), p2(x2,y2)を決め、正方形にするために必要な残りの点をp3(x3,y3), p4(x4,y4)とする。
このp3,p4の柱が存在するかをチェックして、両方が存在するなら面積を比較する。

p2-p1をdx,dyとすると、
  dx = x2 - x1
  dy = y2 - y1
となり、p3,p4の座標は以下の通りとなる。
  p3 = (x2 - dy, y2 + dx) = (x2 - y2 + y1, y2 + x2 - x1)
  p4 = (x1 - dy, y1 + dx) = (x1 - y2 + y1, y1 + x2 - x1)

p3, p4が存在すれば、面積を計算して比較する。
１辺の長さは、sqrt(dx^2 * dy^2)なので、面積は dx^2 * dy^2 になる。
正方形が座標軸に平行でない場合でも、面積は必ず整数値になるのでint型でよい。

*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }


const int CMAX = 5000;

int main(){
    int n;
    cin >> n;
    int ans = 0;

    vi x(CMAX), y(CMAX);
    vector<vector<bool>> c(CMAX+1, vector<bool>(CMAX+1, false));

    rep(i,n){
        cin >> x[i] >> y[i];
        c[x[i]][y[i]] = true;
    }

    rep(i,n){
        rep(j,n){
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];

            int x3 = x[j] - dy;
            int y3 = y[j] + dx;
            int x4 = x[i] - dy;
            int y4 = y[i] + dx;

            if(min({x3,y3,x4,y4}) < 0 || max({x3,y3,x4,y4}) > CMAX) continue;
            if(c[x3][y3] == false || c[x4][y4] == false) continue;

            int s = dx*dx + dy*dy;
            chmax(ans, s);
        }
    }
    cout << ans << endl;
}
