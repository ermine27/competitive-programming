/*
単一始点最短経路(SSSP)

ダイクストラ法
グラフを隣接行列で持つ
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define fore(x, a) for (auto& x : a)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

vvi a;
vi d;
int n;

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    fill(all(d), INT_MAX);

    d[0] = 0;
    q.push(pii(0, s));
    while (q.empty() == false) {
        int di = q.top().first;
        int ui = q.top().second;
        q.pop();

        rep(i, n) {
            if (a[ui][i] >= 0 && di + a[ui][i] < d[i]) {
                d[i] = di + a[ui][i];
                q.push(pii(d[i], i));
            }
        }
    }
}

int main() {
    cin >> n;
    a.resize(n, vi(n));
    d.resize(n);

    rep(i, n) {
        int u, ki, vi, ci;
        cin >> u >> ki;
        rep(j, n) a[i][j] = -1;
        rep(j, ki) {
            cin >> vi >> ci;
            a[i][vi] = ci;
        }
    }

    dijkstra(0);
    
    rep(i,n){
        cout << i << ' ' << d[i] << endl;
    }

    return 0;
}
