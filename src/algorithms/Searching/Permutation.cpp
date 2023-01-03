/**
 * 順列全探索
 *
 * @brief 順列全探索
 * @remark 計算量：O(n!)
 * @remark n<=10まで (10! = 3628000 --> 10^6)
 * 
 * 問題例
 * ABC 145-C Average Length
 * https://atcoder.jp/contests/abc145/tasks/abc145_c
 */

#include "../header.cpp"


int main() {
    int n;
    double ans = 0.0;
    cin >> n;
    vi x(n),y(n),c(n);
    rep(i,n) cin >> x[i] >> y[i];

    rep(i,n) c[i]=i;
    // この書き方でも同じ
    // iota(all(c), 0);

    int cnt = 0;
    do{
        ++cnt;
        double dist = 0.0;
        rep(i,n-1){
            dist += sqrt( pow(x[c[i]] - x[c[i+1]], 2) + pow(y[c[i]] - y[c[i+1]],2) );
        }
        ans += dist;
    }while(next_permutation(all(c)));

    cout << fixed << setprecision(10);
    cout << ans / cnt;
}