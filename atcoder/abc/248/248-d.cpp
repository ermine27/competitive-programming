/*
Aに出てきた要素のindexを記録していく
LとRに対して、indexを二分探索する
*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using vvi = vector<vi>;


int main(){
    int N,Q;
    cin >> N;
    vi A(N+1);
    reps(i, 1, N+1) cin >> A[i];
    cin >> Q;
    vi L(Q), R(Q), X(Q);
    rep(i,Q) cin >> L[i] >> R[i] >> X[i];

    vvi c(N+1);
    reps(i,1,N+1){
        c[A[i]].push_back(i);
    }

    rep(i,Q){
        auto l = lower_bound(c[X[i]].begin(), c[X[i]].end(), L[i]);
        auto r = upper_bound(c[X[i]].begin(), c[X[i]].end(), R[i]);
        cout << r - l << endl;
    }

    return 0;
}
