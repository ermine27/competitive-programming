/**
 * bit全探索
 *
 * @brief bit全探索
 * @remark 計算量：O(2^n)
 * @remark n=20まで (2^20 --> 10^6, n=30 --> 10^9)
 * 
 * 問題例
 * ITP2_11_A Enumeration of Subsets I
 * https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/11/ITP2_11_A
 * ABC 128-C Switches
 * https://atcoder.jp/contests/abc128/tasks/abc128_c
 */

#include "../header.cpp"


int main() {
    int n;
    cin >> n;

    rep(i,1<<n){
        bitset<18> bs(i);

        // bitsetから整数へ変換するにはto_ullong()を使う
        cout << i << ' ' << bs.to_ullong() << ' ' << ':';
        rep(j,n){
            if (bs[j]) cout << ' ' << j;
        }
        cout << endl;
    }

    return 0;
}
