#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 2e9;


int main(){
    int n;
    cin >> n;
    map<int,int> m;
    m[0] = 0;

    rep(i,n){
        int ti;
        cin >> ti;
        map<int,int> m2 = m;

        fore(mi, m2){
            m[mi.first + ti] = mi.second;
            m[mi.first] = mi.second + ti;
        }
    }

    int ans = INF;
    fore(mi, m){
        chmin(ans, max(mi.first, mi.second));
    }

    cout << ans;
}
