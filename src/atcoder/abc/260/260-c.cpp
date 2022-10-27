#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

vl red(11), blue(11);
int n, x, y;

void dfs(int level) {
    if (level < 2) return;

    if (red[level]) {
        red[level - 1] += red[level];
        blue[level] += red[level] * x;
        red[level] = 0;
    }
    if (blue[level]) {
        red[level - 1] += blue[level];
        blue[level - 1] += blue[level] * y;
        blue[level] = 0;
    }

    dfs(level - 1);
}

int main() {
    cin >> n >> x >> y;
    red[n] = 1;

    dfs(n);
    cout << blue[1];
    return 0;
}
