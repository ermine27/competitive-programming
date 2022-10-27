#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n, k;
    cin >> n >> k;
    set<int> aa;
    vector<double> x(n), y(n), a(k), b(n-k);
    rep(i,k){
        int ai;
        cin >> ai;
        a[i] = ai-1;
        aa.insert(ai-1);
    }
    rep(i,n) cin >> x[i] >> y[i];

    double ans = 0.0;

    rep(i,n){
        if(aa.count(i)) continue;

        double dist = 1e9;
        rep(j,n){
            if(!aa.count(j)) continue;
            double di = sqrt((1.0 * x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            chmin(dist, di);
        }
        chmax(ans, dist);
    }

    cout << fixed << setprecision(10);
    cout << ans;

    return 0;
}
