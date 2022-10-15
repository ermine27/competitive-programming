/*
最小全域木(MST)

プリム法を使って解く
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vvi = vector<vi>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vvi a;
vector<bool> v;
int n;

int prim(int x) {
    int weight = 0;
    v[x] = true;
    while (count(all(v), true) < n) {
        int next = -1;
        int min_weight = INT_MAX;
        rep(i, n) {
            if (!v[i]) continue;

            rep(j, n) {
                if (v[j] || a[i][j] < 0) continue;

                if (chmin(min_weight, a[i][j])) {
                    next = j;
                }
            }
        }

        v[next] = true;
        weight += min_weight;
    }

    return weight;
}

int main() {
    cin >> n;
    a.resize(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    v.resize(n);

    cout << prim(0) << endl;

    return 0;
}
