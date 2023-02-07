#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<int> wsum(h), hsum(w);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) wsum[i] += a[i][j];
    for (int j = 0; j < w; j++)
        for (int i = 0; i < h; i++) hsum[j] += a[i][j];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j != 0)
                cout << ' ';
            cout << wsum[i] + hsum[j] - a[i][j];
        }
        cout << endl;
    }

    return 0;
}