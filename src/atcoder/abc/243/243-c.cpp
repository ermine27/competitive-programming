#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1e9 + 7;


int main(){
    int n;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    string s;
    cin >> s;

    map<int,pii> m;
    int xi,yi,si;
    rep(i, n){
        xi = x[i];
        yi = y[i];
        si = s[i];
        if(m.count(yi)){
            if(si == 'L')
                chmax(m[yi].first, xi);
            else
                chmin(m[yi].second, xi);
        } else {
            if(si == 'L')
                m[yi] = make_pair(xi, INF);
            else
                m[yi] = make_pair(-INF, xi);
        }
    }

    string ans = "No";

    fore(x, m){
        int maxL = x.second.first;
        int minR = x.second.second;

        if(maxL == -INF || minR == INF) continue;
        if(maxL > minR) ans = "Yes";
    }

    cout << ans;

}
