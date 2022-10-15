// mmeo: DropBoxのテストデータがAtCoder側と違っているかも (random07, randome08の２つ)

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


vvi route;
vi step;
vi vst;

void dfs(int cur){

    step.push_back(cur+1);

    fore(x, route[cur]){
        if(vst[x] == 0){
            vst[x] = 1;
            dfs(x);
            step.push_back(cur+1);
        }
    }

}

int main(){
    int n;
    cin >> n;
    int ai, bi;
    route.resize(n);
    vst.resize(n);
    vst[0] = 1;

    rep(i,n-1){
        cin >> ai >> bi;
        --ai; --bi;
        route[ai].push_back(bi);
        route[bi].push_back(ai);
    }

    rep(i,n) sort(all(route[i])); 

    dfs(0);

    fore(x,step) cout << x << ' ';
}
