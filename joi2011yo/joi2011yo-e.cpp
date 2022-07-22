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

int bfs(int x, int y, int n) {
    vvi step;
    int ans = 0;

    repf(k, n) {
        step.assign(h, vi(w, -1));
        step[x][y] = 0;

        queue<pii> q;
        q.push(make_pair(x, y));
        while (q.empty() == false) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            rep(d, 4) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || area[nx][ny] == -1 || step[nx][ny] >= 0)
                    continue;

                step[nx][ny] = step[cx][cy] + 1;
                q.push(make_pair(nx, ny));

                if (area[nx][ny] == k) {
                    ans += step[nx][ny];
                    x = nx;
                    y = ny;
                    // while (q.empty() == false) q.pop();
                    break;
                }
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> h >> w >> n;
    area.resize(h, vi(w));

    int sx, sy;
    rep(i, h) rep(j, w) {
        char c;
        cin >> c;
        if (c == 'S') {
            sx = i;
            sy = j;
        }
        if (c == 'X') {
            area[i][j] = -1;
        }
        if (isdigit(c)) {
            area[i][j] = c - '0';
        }
    }

    cout << bfs(sx, sy, n) << endl;
    return 0;
}
