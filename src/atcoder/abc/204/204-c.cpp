#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define npos string::npos
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;

vector<bool> vst(2000);
vvi route;

void dfs(int st){
    if(vst[st]) return ;
    vst[st] = true;

    fore(x,route[st]){
        dfs(x);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int ai,bi;
    route.resize(n);
    rep(i, m){
        cin >> ai >> bi;
        route[ai-1].push_back(bi-1);
    }

    ll ans = 0;
    rep(i,n){
        rep(j,n) vst[j] = false;
        dfs(i);
        rep(j,n){
            if(vst[j] == true) ++ans;
        }
    } 
    cout << ans;
}
