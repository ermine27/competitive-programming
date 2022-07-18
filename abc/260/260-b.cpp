#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    set<int> ans;

    rep(i, x) {
        int xi = -1;
        int hc = -1;
        rep(j, n) {
            if (!ans.count(j) && chmax(hc, a[j])) xi = j;
        }
        ans.insert(xi);
    }

    rep(i, y) {
        int yi = -1;
        int hc = -1;
        rep(j, n) {
            if (!ans.count(j) && chmax(hc, b[j])) yi = j;
        }
        ans.insert(yi);
    }

    rep(i, z) {
        int xy = -1;
        int hc = -1;
        rep(j, n) {
            if (!ans.count(j) && chmax(hc, a[j] + b[j])) xy = j;
        }
        ans.insert(xy);
    }

    fore(x, ans) cout << x + 1 << endl;

    return 0;
}
