/*
単一始点最短経路(SSSP)

ダイクストラ法
グラフを隣接リストで持つ
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define fore(x, a) for (auto& x : a)
#define fore2(k,v,a) for(auto& [k,v] : a)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using pii = pair<int,int>;

vector<vector<pii>> a;
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
        fore2(uu,dd, a[ui]){
            if(di+dd < d[uu]){
                d[uu] = di+dd;
                q.push(pii(d[uu],uu));
            }
        }
    }
}

int main() {
    cin >> n;
    a.resize(n);
    d.resize(n);

    rep(i, n) {
        int u, ki, vi, ci;
        cin >> u >> ki;
        rep(j, ki) {
            cin >> vi >> ci;
            a[i].push_back(make_pair(vi,ci));
        }
    }

    dijkstra(0);
    
    rep(i,n){
        cout << i << ' ' << d[i] << endl;
    }

    return 0;
}
