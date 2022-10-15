/*
TLE

vectorをsetに変えるか、cin,coutを書きかえる
（もしくは ios::sync_with_stdio(false);　cin.tie(nullptr); を記述する）
のどれかをしないと実行時間制限に間に合わない

コメントの部分はあまり差はない

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
using ll = long long;
using vl = vector<long long>;

int main(){
    ll L;
    int Q;
    cin >> L >> Q;
    vl w;
    w.push_back(0);
    w.push_back(L);

    rep(i,Q){
        int ci;
        ll xi;
        cin >> ci >> xi;
        auto it = lower_bound(all(w), xi);

        if(ci == 1){
            w.insert(it,xi);
        } else {
            // int idx = it - w.begin();
            // ll left = w[idx-1];
            // ll right = w[idx];
            // cout << right - left << endl;

            cout << *it - *prev(it) << endl;
        }
    }
}
