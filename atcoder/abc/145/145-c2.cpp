#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
using vi = vector<int>;


int main(){
    int n;
    cin >> n;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vi c(n);
    rep(i,n) c[i] = i;

    double sum = 0.0;

    do{
        rep(i,n-1){
            int p1 = c[i], p2 = c[i+1];
            sum += sqrt((x[p1] - x[p2])*(x[p1] - x[p2]) + (y[p1] - y[p2])*(y[p1] - y[p2]));
        }
    }while(next_permutation(all(c)));

    int fact = 1;
    for(int i = 1; i <= n; ++i) fact *= i;

    cout << fixed << setprecision(10);
    cout << sum / fact;
}
