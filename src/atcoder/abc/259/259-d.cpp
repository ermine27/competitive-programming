#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;


vvi m(3000);
vl v(3000);


ll pow2(ll x){ return x*x; }

ll dist2(ll x1,ll y1,ll x2,ll y2){
    return pow2(x1-x2)+pow2(y1-y2);
}

bool dfs(int cur, int goal){
    if(cur == goal) return true;

    fore(x,m[cur]){
        if(v[x]) continue;
        v[x] = 1;
        if(dfs(x,goal)) return true;
    }

    return false;
}

int main(){
    int n;
    ll sx,sy,tx,ty;
    cin >> n >> sx>>sy>>tx>>ty;
    vl x(n), y(n), r(n);
    rep(i,n) cin >> x[i] >> y[i]>> r[i];

    int si,ti;
    rep(i,n){
        if(dist2(sx,sy,x[i],y[i]) == pow2(r[i])) si=i;
        if(dist2(tx,ty,x[i],y[i]) == pow2(r[i])) ti=i;
    }

    rep(i,n-1){
        reps(j,i+1,n){
            ll d2 = dist2(x[i],y[i],x[j],y[j]);

            if(d2 > pow2(r[i]+r[j]) || d2 < pow2(r[i]-r[j])){
            } else {
                m[i].push_back(j);
                m[j].push_back(i);
            }

        }
    }

    bool ok = dfs(si,ti);

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
