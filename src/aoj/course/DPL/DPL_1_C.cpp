/*
ナップサック問題（個数制限なし）

漸化式を少し変えることで個数制限なしの場合のDPができる。
i番目の品物を選ぶ時の遷移元をdp[i-][j]からdp[i][j]に変えるだけ。
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using vi = vector<int>;
using vvi = vector<vi>;

int n,m;
vi v,w;

int knapsack(){

    vvi dp(n+1, vi(m+1));

    repf(i,n){
        repf(j,m){
            if(j>=w[i]){ 
                dp[i][j] = max(dp[i][j-w[i]]+v[i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

int main(){
    cin >> n >> m;
    v.resize(n+1);
    w.resize(n+1);
    repf(i, n) cin >> v[i] >> w[i];

    cout << knapsack() << endl;
    return 0;
}
