/*
vectorを使って解く

数直線上の（１）両端の位置と、（２）開始／終了のどちらか、
このペアの情報だけあれば計算できる
*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using pii = pair<int,int>;


int main(){
    int n;
    cin >> n;
    vector<pii> p;
    rep(i,n){
        int ai,bi;
        cin >> ai >> bi;
        p.push_back(make_pair(ai,1));
        p.push_back(make_pair(ai + bi, -1));
    }

    sort(all(p));

    vi ans(n+1);
    int ct = 0;
    rep(i, n*2-1){
        ct += p[i].second;
        ans[ct] += p[i+1].first - p[i].first;
    }

    rep(i,n){
        cout << ans[i+1] << ' ';
    }

}
