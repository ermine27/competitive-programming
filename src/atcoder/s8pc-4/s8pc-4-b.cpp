/*
Kを使ってビット全探索をする。
K個以上とあるが、コストは「K個見える場合≦K+1個見える場合」となるはずなので、
ビットが立っているものだけが見える場合のみ計算すればよい。
つまり、ビットが立っている数がKちょうどでない場合は計算は省略できる。

計算方法の考え方としては、以下の2つの条件を満たせればよい。
・K(k[1],k[2],...,k[m])の建物について、高さが k[1] < k[2] < k[3] < ... < k[m] となっている
・任意のki, ki+1において、2つの間にk1+1より高い建物が存在しない

各ビットパターンにおいて条件を満たしつつ、コストを計算する。
Aを左から見ていって、以下のような手順で行えばよい。
　A[i] < A[i+1] の場合は何もしなくてよい
　A[i] >=A[i+1] の場合、
　　A[i+1]がKに含まれているなら、A[i+1]の高さをA[i]+1まで増やし、コストも加算する
　　A[i+1]がKに含まれていない場合はKとは関係ないので何もしない

最終的に、各ビットパターンで計算したコストの最小が答えとなる。

*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    ll ans = LONG_LONG_MAX;
    rep(i, 1<<n){
        bitset<15> bs = i;
        if((int)bs.count() != k) continue;

        // 左から順に、1つ右隣と比較したいのでAを更新してもいいようにコピーする
        vi b = a;
        ll cost = 0;
        rep(j,n-1){
            int d = b[j] - b[j+1];

            // 右隣の建物のほうが低いか同じ、かつKの対象であれば右隣の建物の高さを増やす
            if(d >= 0 && bs[j+1] == 1){
                cost += d+1;
                b[j+1] += d+1;
            } else {
                b[j+1] = max(b[j+1], b[j]);
            }
        }
        chmin(ans, cost);
    }

    cout << ans << endl;
}
