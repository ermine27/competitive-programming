#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }

// 累積和＋二分探索
int main(){
    ll n,p,q,r;
    in(n,p,q,r);
    vl a(n), b(n+1);
    rep(i,n) in(a[i]);
    rep(i,n) b[i+1] = b[i] + a[i];

    fore(x,b){
        if(binary_search(all(b),x+p) && binary_search(all(b),x+p+q) && binary_search(all(b),x+p+q+r)){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}


// 二分探索をsetで行う
int main2(){
    ll n,p,q,r;
    in(n,p,q,r);
    vl a(n), b(n+1);
    set<ll> s;
    s.insert(0);
    rep(i,n) in(a[i]);
    rep(i,n){
        b[i+1] = b[i] + a[i];
        s.insert(b[i+1]);
    }

    fore(x,s){
        if(s.count(x+p) && s.count(x+p+q) && s.count(x+p+q+r)){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}


// 累積和を全て保持する必要はないので１つの変数を使って更新していく
int main3(){
    ll n,p,q,r,ai,bi=0;
    in(n,p,q,r);
    set<ll> s;
    s.insert(0);
    rep(i,n){
        in(ai);
        bi += ai;
        s.insert(bi);
    }

    fore(x,s){
        if(s.count(x+p) && s.count(x+p+q) && s.count(x+p+q+r)){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
