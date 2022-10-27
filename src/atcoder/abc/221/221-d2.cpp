/*
mapを使った解く
mapにすればsort()を書く必要はない
始端/終端の繰り返し部分は集約されるので、範囲for文の繰り返しは場合により少なくなる
でも実行時間はvectorの倍かかってる。。
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;


int main(){
    int n;
    cin >> n;
    map<int,int> m;
    rep(i,n){
        int ai,bi;
        cin >> ai >> bi;
        m[ai]++;
        m[ai+bi]--;
    }

    vi ans(n+1);
    int ct = 0, ct2 = -1;

    // C++17 構造化束縛を使う
    for(const auto& [k,v] : m){
        ans[ct] += k - ct2;
        ct2 = k;
        ct += v;
    }
    // C++17以前では上記の書き方は不可。以下の書き方になる。
    // for(auto x : m){
    //     ans[ct] += x.first - ct2;
    //     ct2 = x.first;
    //     ct += x.second;
    // }

    rep(i,n){
        cout << ans[i+1] << ' ';
    }
}

