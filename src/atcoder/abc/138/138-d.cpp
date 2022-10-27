#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define fore(x,a) for(auto& x:a)
#define fore2(k,v,a) for(auto& [k,v] : a)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;


vi ans;
vvi children;

void dfs(int x, int pre){
    if (pre != -1) ans.at(x) += ans.at(pre);

    fore(xx, children.at(x)) {
        if (xx == pre) continue;
        dfs(xx, x);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    ans.resize(n + 1);
    children.resize(n + 1);
    int ai, bi, pi, xi;
    repf(i, n - 1) {
        cin >> ai >> bi;
        children[ai].push_back(bi);
        children[bi].push_back(ai);
    }

    rep(i, q) {
        cin >> pi >> xi;
        ans[pi] += xi;
    }

    dfs(1, -1);

    repf(i,n){
        if (i != 1) cout << ' ';
        cout << ans[i];
    }

    return 0;
}
