#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using vi = vector<int>;
using vvi = vector<vi>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int BITMAX = 12;

bool judge(bitset<BITMAX> b, vi &c, vvi &a, int x){
    int m = a[0].size();
    vi sa(m);
    rep(i,c.size()){
        if(b[i]){
            rep(j,m) sa[j] += a[i][j];
        }
    }

    rep(i,m){
        if(sa[i] < x) return false;
    }

    return true;
}

int main() {
    int n,m,x,aij,ans=INT_MAX;
    bool ok = false;
    cin >> n >> m >> x;
    
    vi c(n);
    vvi a(n);

    rep(i,n){
        cin >> c[i];
        rep(j,m){
            cin >> aij;
            a.at(i).push_back(aij);
        } 
    }

    rep(i,1<<n){
        bitset<BITMAX> b = i;
        int ct = 0;
        rep(j,n) ct += b[j] * c[j];

        if(judge(b,c,a,x)){
            ok = true;
            chmin(ans,ct);
        }

    }
    if(ok) cout << ans;
    else cout << -1;
}