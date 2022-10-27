#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& (x):(a))
using ll = long long;

int main(){
    ll n;
    int ai;
    cin >> n;
    map<int,int> a;
    rep(i, n){
        cin >> ai;
        if(a.count(ai)) a[ai]++;
        else a[ai] = 1;
    }

    ll p1,p2;
    p1 = n * (n-1);
    p2 = 0;
    fore(aa,a){
        ll ac = aa.second;
        if(ac > 1){
            p2 += ac * (ac-1);
        }
    }

    cout << (p1 - p2) / 2;
}