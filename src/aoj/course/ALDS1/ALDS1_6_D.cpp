/*
ALDS1_6_D Minimum Cost Sort : 最小コストソート

与えられた荷物の並びに対して、それぞれソート後のどの位置にあるべきかを調べる。
そうすると、いくつかのサイクルができる。

ex.1 
5
1 5 3 4 2

この場合のサイクルは以下の４つ
(1) 1
(2) 5 2
(3) 3
(4) 4

ex.2
7
3 2 8 5 4 1 6

この場合のサイクルは以下の３つ
(1) 3 8 6 1
(2) 2
(3) 5 4

この各サイクルの中でそれぞれコストを計算する
・グループの要素の数が1の場合は交換不要。
・グループの要素の数が2の場合は互いの要素を入れ替えるのでコストは2つの和。
・グループの要素の数が3以上の場合は、グループの最小の値を使って交換することで最小のコストを計算する

ex.2の場合は、
(1) 最小値の1を使って交換を繰り返すと、3+1+8+1+6+1 = (3+8+6) + 1*3 = 20
(2) 交換なし　→0
(3) ２つを入れ替える　→ 5+4 = 9

(1)～(3) の合計なので、20+0+9 = 29が最小コストになる


ただし、この方法では最小コストが求まらないケースがある。

ex.3
6
4 1 9 8 6 7

これをサイクルに分けると、
(1) 4 1
(2) 9 7 8 6

の2つに分かれ、同様にそれぞれのコストを計算すると、
(1) 4+1 = 5
(2) (9+8+7) + 6*3 = 42
となり、(1)+(2) = 47となる。

この場合、(2)の交換にサイクル(2)の最小値の6ではなく(1)から1を借りてくるとコストが更に少なくなる。
1と6を入れ替えてから(2)の交換を行い、最後に再度1と6を入れ替えるので、(1),(2)間の入れ替えは2回、他は1回行うことになる。

(1) 4+1 = 5
(2) (9+1) + (7+1) + (8+1) + (6+1)*2 = (9+7+8) + 1*3 + (6+1)*2 = 41
となり、(1)+(2) = 46となる。

サイクルの要素が3つ以上の場合はこの2通りの方法で計算して、値が小さい方が最小コストになる。
１）サイクル内の要素の最小値を使って交換を繰り返す
　→ 　Σwi - min(wi) + min(wi) * (n-1)
    = Σwi + min(wi) * (n-2)
２）他のサイクルから最小値を借りてくる（xは全ての中からの最小値）
 →  Σwi + min(wi) + (n+1) * x

*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()


int main(){
    int n;
    cin >> n;
    vi w(n), ord(n), t;
    rep(i,n) cin >> w[i];
    t = w;
    sort(all(t));

    // 移動先を調べる
    rep(i,n){
        rep(j,n){
            if(w[i] == t[j]){
                ord[i] = j;
                break;
            }
        }
    }

    // 交換するサイクルを調べる
    vvi cycle(n);
    vector<bool> v(n);
    int vc = 0;
    int p = 0, m = 0;
    while(vc < n){
        while(v[p] == 0){
            cycle[m].push_back(w[ord[p]]);
            v[p] = 1;
            p = ord[p];
            ++vc;
        }

        ++p;
        if(cycle[m].size() > 0) ++m;
    }

    // 各サイクルごとの最小コストを求めていく
    int ans = 0;
    fore(row, cycle){
        int rsize = row.size();
        if(rsize < 2) continue;
        if(rsize == 2) ans += row[0] + row[1];
        if(rsize > 2){
            sort(all(row));

            // 各サイクル内で交換する方法でコストを計算する
            int r1 = accumulate(all(row),0) + (rsize - 2) * row[0];
            // 他のグループから借りて交換する場合（最小値は最初のソート済配列から取ってくる）
            int r2 = accumulate(all(row),0) + row[0] + (rsize + 1) * t[0];

            // aojのジャッジサーバー　gcc 8.3.1 → reduceは入っていない
            // int r1 = reduce(all(row)) + (rsize - 2) * row[0];
            // int r2 = reduce(all(row)) + row[0] + (rsize + 1) * t[0];

            ans += min(r1,r2);
        }       
    }

    cout << ans << endl;
    return 0;    
}
