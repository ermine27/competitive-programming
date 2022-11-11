#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    // 範囲for文を使うと変数を用意せずに同じことができる
    // for(auto &p : xy){
    //     cin >> p.first >> p.second;
    // }

    sort(xy.begin(), xy.end());

    for (int i = 0; i < n; ++i) {
        cout << xy[i].first << ' ' << xy[i].second << endl;
    }
    return 0;
}
