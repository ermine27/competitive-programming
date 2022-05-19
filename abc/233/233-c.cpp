#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vl = vector<long long>;
using vvl = vector<vl>;


ll n,x;
vvl a;
ll ans = 0;

void dfs(ll pos, ll prod){
    if(pos == n){
        if(prod == x) ++ans;
        return;
    }

    fore(aij, a[pos]){
        if(prod*aij > x) continue;
        dfs(pos+1, prod*aij);
    }
}

int main(){
    cin >> n >> x;
    a.resize(n);

    rep(i,n){
        int li;
        cin >> li;
        a[i].resize(li);
        rep(j,li)  cin >> a[i][j];
    }

    dfs(0,1);

    cout << ans;
    return 0;    
}