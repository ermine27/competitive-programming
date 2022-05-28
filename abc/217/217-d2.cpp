/*
set を使って解く。
こちらのほうが一般的な解き方。

二分探索はstd::lower_boundだと計算量がO(N)になるので注意。
set::lower_boundだとO(logN)になる

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
            auto it = s.lower_bound(xi);
            cout <<  *it - *prev(it) << endl;
        }
    }
}
