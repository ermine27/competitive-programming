/*
set を使って解く。
こちらのほうが一般的な解き方。

setを使う際、二分探索はstd::lower_boundを使ってしまうと計算量がO(N)になるので注意。
set::lower_boundだと本来の計算量のO(logN)になる

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    int L, Q;
    cin >> L >> Q;
    set<int> s;
    s.insert(0);
    s.insert(L);

    rep(i,Q){
        int ci, xi;
        cin >> ci >> xi;

      	if(ci == 1){
            s.insert(xi);
        } else {
            // setにはsetのメンバ関数のlower_boundを使う
            auto it = s.lower_bound(xi);
            // NG: 計算量がO(N)になってしまう
            // auto it = lower_bound(s.begin(), s.end(), xi);
            cout <<  *it - *prev(it) << endl;
        }
    }
}
