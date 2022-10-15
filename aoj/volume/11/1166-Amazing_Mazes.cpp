/*
この問題では壁の情報がマスではなく線の部分にあたる。
解き方としては2通り考えられる。

1. 壁の情報を線からマスになるように置き換えて迷図のデータを作る
   （完成した配列は 2h+1 x 2w+1 の大きさになる）
2. このデータ形式のままで判定ができる処理を作る
   マスのデータから探索済かを見て、壁のデータからその方向に進めるかを見るようにする

1のほうがやや簡単かと思うが2の方法で解いた。
*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

// 0:Right, 1:Down, 2:Left, 3:Up
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int wx[] = {0, 0, -1, 0};
const int wy[] = {0, 0, 0, -1};

vvi wallh,wallw;
int h, w;

int bfs(){
    vvi v(h, vi(w));
    v[0][0] = 1;

    queue<pii> q;
    q.push(make_pair(0, 0));
    while (q.empty() == false) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        rep(i, 4) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int mx = cx + wx[i];
            int my = cy + wy[i];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (v[ny][nx] > 0) continue;

            // left / right
            if (i % 2 == 0 && wallw[my][mx]) continue;
            // up / down
            if (i % 2 == 1 && wallh[my][mx]) continue;

            v[ny][nx] = v[cy][cx] + 1;

            if (nx == w - 1 && ny == h - 1) break;

            q.push(make_pair(nx, ny));
        }
    }

    return v[h-1][w-1];
}

int main(){
    while(true){
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        wallh.assign(h - 1, vi(w));
        wallw.assign(h, vi(w - 1));

        rep(i, 2 * h - 1) {
            if (i % 2) {
                rep(j, w) cin >> wallh[i / 2][j];
            } else {
                rep(j, w - 1) cin >> wallw[i / 2][j];
            }
        }

        cout << bfs() << endl;
    }
    return 0;
}
