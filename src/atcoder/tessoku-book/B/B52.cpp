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

// 問題文の通りシミュレーションしてみる
int main() {
    int n, x;
    string a;
    cin >> n >> x >> a;

    queue<int> que;
    que.push(x - 1);
    a[x - 1] = '@';

    while (!que.empty()) {
        x = que.front();
        que.pop();
        int left = x - 1;
        int right = x + 1;
        if (left >= 0 && a[left] == '.') {
            a[left] = '@';
            que.push(left);
        }
        if (x < right && a[right] == '.') {
            a[right] = '@';
            que.push(right);
        }
    }

    cout << a << endl;
    return 0;
}

// シミュレーションした結果は、Xに最も近い左右の黒の間にある白をを青にしたものになる
int main2() {
    int n, x, c;
    string a;
    cin >> n >> x >> a;
    c = x - 1;
    while (c >= 0 && a[c] == '.') {
        a[c] = '@';
        c--;
    }
    c = x;
    while (c < n && a[c] == '.') {
        a[c] = '@';
        c++;
    }
    cout << a << endl;
    return 0;
}
