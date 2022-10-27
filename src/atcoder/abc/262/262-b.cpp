#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
    int n, m;
    cin >> n >> m;
    vvi s(n, vi(n));

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        s[u - 1][v - 1] = 1;
        s[v - 1][u - 1] = 1;
    }

    int ans = 0;
    rep(i, n - 2) reps(j, i + 1, n - 1) reps(k, j + 1, n) {
        if (s[i][j] && s[j][k] && s[k][i]) ++ans;
    }

    cout << ans << endl;
    return 0;
}
