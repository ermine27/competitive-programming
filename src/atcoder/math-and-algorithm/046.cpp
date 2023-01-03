#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int main() {
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    --sy;
    --sx;
    --gy;
    --gx;
    vector<string> m(r);
    vector<vector<int>> s(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++) cin >> m[i];

    s[sy][sx] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    while (!q.empty()) {
        int y, x, ny, nx;
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (m[ny][nx] == '.' && s[ny][nx] < 0) {
                q.push(make_pair(ny, nx));
                s[ny][nx] = s[y][x] + 1;
            }
        }
    }
    cout << s[gy][gx] << endl;
    return 0;
}
