#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;


int main(){
    int n,ti;
    cin >> n;
    map<int,int> a, b;
    rep(i,n){ cin >> ti; --ti; a[ti]++; }
    rep(i,n){ cin >> ti; --ti; b[i] = a[ti]; }

    ll ans = 0;
    rep(i,n){
        cin >> ti;
        --ti;
        ans += b[ti];
    }
    cout << ans;
}