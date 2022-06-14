/*
B（中部）を固定して、B>A, B<Cの数を二分探索を使って数える。
各Biにおいて、A*Cが組み合わせ数となるので、この和が答えとなる。

A（上部）→B（中部）→C(下部）の順、もしくは逆にC→B→Aの順番で探索すると、
例えばAiの組み合わせを探すときに Ai<B を満たす各Bの要素について、更にB<Cを満たすCの要素を探しに行くので二重ループになってTLEする。
累積和を使うことでACさせることはできるが、ソースは長くなるし実行時間も長くなる。

*/


#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;

int main(){
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];

    sort(all(a));
    sort(all(b));
    sort(all(c));

    ll ans = 0;
    rep(i,n){
        ll up = lower_bound(all(a), b[i]) - a.begin();
        ll down = c.end() - upper_bound(all(c), b[i]);
        ans += up * down;
    }

    cout << ans;
    return 0;
}
