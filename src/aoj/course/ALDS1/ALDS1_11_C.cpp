/*
幅優先探索(BFS)
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& x:a)
using vi = vector<int>;
using vvi = vector<vi>;

vvi g;
vi d;

void bfs(int x){
    d[x]=0;
    queue<int> q;
    q.push(x);

    while(q.empty() == false){
        int cur = q.front();
        q.pop();

        fore(x,g[cur]){
            if (d[x] == -1) {
                d[x] = d[cur] + 1;
                q.push(x);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    g.resize(n);
    d.resize(n,-1);

    rep(i,n){
        int u,ki,v;
        cin >> u >> ki;

        rep(j,ki){
            cin >> v;
            g[i].push_back(v-1);
        }
    }

    bfs(0);

    rep(i,n){
        cout << i+1 << ' ' << d[i] << endl;
    }

    return 0;
}
