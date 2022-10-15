/*
- BFSで解く
- 外から見える部分を探したい → 建物がない場所を探索する
- 地図の外側は自由に行き来できるとあるので、二次元配列の外枠を設け、値は0（建物がない時）とする
    - こうすることで常に(0,0)から探索が開始できる
- 正六角形の周囲を調べる方法は入力の規則を使って求める
    - 2次元配列の上下左右4方法や斜めを加えた8方向を探索する際に使うdx, dyの配列をこの問題用に作る
    - yが奇数の場合と偶数の場合で異なるので２つ用意しておく
- 6方向の探索において、建物である場合はそこが飾り付けが必要な点になるので、その数を数えていくと求めたい答えが求まる

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

// [0]y=even, [1]y=odd
const int dx[2][6] = {{-1, 0, 1, 0, -1, -1}, {0, 1, 1, 1, 0, -1}};
const int dy[2][6] = {{-1, -1, 0, 1, 1, 0}, {-1, -1, 0, 1, 1, 0}};
const int EMPTY = 0;
const int BUILDING = 1;
const int VISITED = 2;

vvi area;
int h, w;

int bfs(){
    int ans = 0;
    area[0][0] = VISITED;

    queue<pii> q;
    q.push(make_pair(0, 0));
    while (q.empty() == false) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        int md = (cy % 2 == 0 ? 0 : 1);
        rep(i, 6) {
            int nx = cx + dx[md][i];
            int ny = cy + dy[md][i];

            if (nx < 0 || nx > w + 1 || ny < 0 || ny > h + 1 || area[ny][nx] == VISITED) {
                continue;
            }
            if (area[ny][nx] == BUILDING) {
                ++ans;
            }
            if (area[ny][nx] == EMPTY) {
                area[ny][nx] = VISITED;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return ans;
}

int main(){
    cin >> w >> h;
    area.resize(h + 2, vi(w + 2, 0));
    repf(i, h) repf(j, w) cin >> area[i][j];

    cout << bfs() << endl;
    return 0;
}
