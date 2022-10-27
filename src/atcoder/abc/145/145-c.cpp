#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
using vi = vector<int>;


int main() {
    int n;
    double ans = 0.0;
    cin >> n;
    vi x(n),y(n),c(n);

    rep(i,n) cin >> x[i] >> y[i];
    rep(i,n) c[i]=i;

    int ct = 0;
    do{
        ++ct;
        double dist = 0.0;
        rep(i,n-1){
            dist += sqrt( pow(x[c[i]] - x[c[i+1]], 2) + pow(y[c[i]] - y[c[i+1]],2) );
        }
        ans += dist;
    }while(next_permutation(all(c)));

    cout << fixed << setprecision(10);
    cout << ans / ct;
}