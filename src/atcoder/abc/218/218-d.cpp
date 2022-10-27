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


int main(){
    int n;
    cin >> n;
    map<int,vi> cd;
    int xi,yi;
    rep(i, n){
        cin >> xi >> yi;
        cd[xi].push_back(yi);
    }

    vvi a;
    fore(x,cd){
        sort(all(cd[x.first]));
        a.push_back(cd[x.first]);
    }

    int asize = a.size();
    ll ans = 0;
    rep(i,asize-1){
        reps(j,i+1,asize){
            vi result;
            set_intersection(all(a[i]),all(a[j]),inserter(result, result.end()));
            int rsize = result.size();
            if(rsize >= 2){
                ans += rsize * (rsize-1) / 2;
            }
        }
    }

    cout << ans;
}

