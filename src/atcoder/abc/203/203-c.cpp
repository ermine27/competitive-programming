#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
using ll = long long;

int main(){
    int n;
    ll k,ai,bi,next,c=0;
    cin >> n >> k;
    map<ll,ll> ab;
    rep(i, n){
        cin >> ai >> bi;
        ab[ai] += bi;
    }
    fore(x,ab){
        ai = x.first;
        bi = x.second;
        next = ai - c;

        if(next > k) break;

        c += next; 
        k = k - next + bi;
    }
    cout << c + k;
}