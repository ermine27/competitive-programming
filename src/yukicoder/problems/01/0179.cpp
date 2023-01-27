#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n = 0;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#')
                n++;
        }
    }

    for (int x = -h; x <= h; x++) {
        for (int y = -w; y <= w; y++) {
            if (x == 0 && y == 0)
                continue;
            vector<vector<bool>> vst(h, vector<bool>(w));
            int pnt = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] != '#')
                        continue;

                    int xx = i + x;
                    int yy = j + y;
                    if (xx < 0 || xx >= h || yy < 0 || yy >= w) {
                        continue;
                    }

                    if (s[i][j] == '#' && s[xx][yy] == '#' && !vst[i][j] && !vst[xx][yy]) {
                        vst[i][j] = vst[xx][yy] = 1;
                        pnt += 2;
                    }
                }
            }

            if (pnt == n && pnt > 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
