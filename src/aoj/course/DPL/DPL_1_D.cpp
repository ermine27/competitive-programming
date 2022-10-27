/*
最長増加部分列 (LIS: Longest Increasing Subsequence)

main ,main2, main3 の３つどれでもAC
*/
#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f

#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)

#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using vi = vector<int>;


int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi dp(n);
    dp[0] = a[0];

    int len = 1;
    rep(i,n){
        if(dp[len-1] < a[i]){
            dp[len++] = a[i];
        } else {
            int idx = lower_bound(dp.begin(), dp.begin()+len, a[i]) - dp.begin();
            dp[idx] = a[i];
        }
    }

    cout << len << endl;
    return 0;
}


int main2(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi dp;
    dp.push_back(a[0]);

    rep(i, n) {
        if (*dp.rbegin() < a[i]) {
            dp.push_back(a[i]);
        } else {
            int idx = lower_bound(all(dp), a[i]) - dp.begin();
            dp[idx] = a[i];
        }
    }

    cout << sz(dp) << endl;
    return 0;
}


int main3(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi dp(n + 1, INT_MAX);
    dp[0] = -1;

    rep(i, n) {
        int idx = lower_bound(all(dp), a[i]) - dp.begin();
        dp[idx] = a[i];
    }

    cout << lower_bound(all(dp), INT_MAX) - dp.begin() - 1 << endl;
    return 0;
}
