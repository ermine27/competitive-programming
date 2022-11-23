/**
 * ABC 190-D Staircase Sequences
 *
 * 初項a, 公差d(=1)，項数n，末項l(=a+n-1)とすると、等差数列の総和Sは
 *  S = n(a+l)/2 = (2a+n-1)*n/2
 * で表せる。これを整理すると、
 *  2S = (2a+n-1)*n
 * となり、aについて変形すると、
 *  a = {(2S/n)-n+1}/2
 * となる。
 * ここで、aが整数であるためには{(2S/n)-n+1}/2が偶数である必要があり、さらにそのためには(2S/n)が整数ある必要がある。
 * (2S/n)が整数であるためにはnは2Sの約数になる必要がある。
 * 2Nまでの約数を全て求めて、その約数を上の式に当てはめて右辺が整数になるかを調べる。
 * 両方の条件を満たすものが条件に当てはまる初項の値になるのでこれを数え上げる。
 *
 *（別の考え方）
 * 数列の平均値をx,項数n とすると、等差数列の総和Sは S=xn となる。
 * xは（初項＋末項）/2 なので、2xは整数となる。式を変形すると 2S=xn となるので、2Sの約数を求めて、
 * その約数に対して数式ができるかを判定して答えを求めることができる。
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fore(x, a) for (auto&(x) : (a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
const int INF = 1e9;
const long long INFLL = 1e18;

vl divisor(ll x) {
    vl ans;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ans.push_back(i);
            if (i * i != x) {
                ans.push_back(x / i);
            }
        }
    }

    sort(all(ans));
    return ans;
}

int main() {
    ll n;
    cin >> n;

    vl d = divisor(n * 2);

    int ans = 0;
    fore(k, d) {
        if (((2 * n / k - k + 1) % 2) == 0) {
            ++ans;
        }
    }

    cout << ans << endl;
}