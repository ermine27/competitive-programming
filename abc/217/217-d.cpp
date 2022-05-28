/*
vectorを使った場合

入出力のところで、scanf/printfを使うか以下の記述を入れないとTLEする

ios::sync_with_stdio(false);
cin.tie(nullptr);

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
using vi = vector<int>;

int main(){
    int L, Q;
    cin >> L >> Q;
    vi w;
    w.push_back(0);
    w.push_back(L);

    rep(i,Q){
        int ci, xi;
        scanf("%d %d", &ci, &xi);
        auto it = lower_bound(all(w), xi);

        if(ci == 1){
            w.insert(it,xi);
        } else {
            printf("%d\n", *it - *prev(it));
        }
    }
}
