#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int main() {
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vector<vector<char>> m(r, vector<char>(c));
    vector<vector<int>> step(r, vector<int>(c, -1));
    rep(i, r) {
        rep(j, c) { cin >> m[i][j]; }
    }

    step[sy][sx] = 0;
    queue<pair<int, int>> que;
    que.push({sy, sx});
    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        if (y == gy && x == gx) {
            break;
        }
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || m[ny][nx] == '#' || step[ny][nx] != -1)
                continue;
            step[ny][nx] = step[y][x] + 1;
            que.push({ny, nx});
        }
    }

    cout << step[gy][gx] << endl;
    return 0;
}
