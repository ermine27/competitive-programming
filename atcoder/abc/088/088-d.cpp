#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

vvi area;
int h, w;

int bfs() {
    vvi step;
    step.assign(h, vi(w));
    step[0][0] = 1;

    queue<pii> q;
    q.push(make_pair(0,0));
    while (q.empty() == false) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        rep(d, 4) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h || area[ny][nx] == 1 || step[ny][nx] > 0)
                continue;

            step[ny][nx] = step[cy][cx] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return step[h-1][w-1];
}

int main(){
    cin >> h >> w;
    area.resize(h, vi(w));
    int black=0;

    rep(i, h) rep(j, w) {
        char c;
        cin >> c;
        if (c == '#') {
            ++black;
            area[i][j] = 1;
        } else {
            area[i][j] = 0;
        }
    }

    int step = bfs();
    if (step == 0)
        cout << -1 << endl;
    else
        cout << w * h - step - black << endl;
    return 0;
}
