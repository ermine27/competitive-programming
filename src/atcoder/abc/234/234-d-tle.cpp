// TLE

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using vi = vector<int>;


int main(){
    int n,k,si;
    cin >> n >> k;
    vi p(k-1);
    rep(i,k-1) cin >> p[i];
    sort(all(p));

    rep(i,n-k+1){
        cin >> si;

        auto it = lower_bound(all(p), si);
        p.insert(it, si);
        it = p.begin() + (p.size() - k);
        cout << *it << endl;
    }

    return 0;
}

// 1回の二分探索の処理数を減らせるようerase処理を加えてみたがこっちもTLE
int main2(){
    int n,k,si;
    cin >> n >> k;
    vi p(k-1);
    rep(i,k-1) cin >> p[i];
    sort(all(p));

    rep(i,n-k+1){
        cin >> si;

        auto it = lower_bound(all(p), si);
        p.insert(it, si);
        if(i > 0){
            p.erase(p.begin());
        }
        cout << *p.begin() << endl;
    }

    return 0;
}
