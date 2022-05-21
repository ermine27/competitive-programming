#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;


int main(){
    int n, w;
    cin >> n >> w;
    vi a(n);
    rep(i,n) cin >> a[i];
    set<int> ans;

    rep(i,n){
        int t = a[i];
        if(t <= w) ans.insert(t);
    }
    rep(i,n-1) reps(j,i+1,n){
        int t =a[i]+a[j];
        if(t <= w) ans.insert(t);
    }
    rep(i,n-2) reps(j,i+1,n-1) reps(k,j+1,n){
        int t = a[i]+a[j]+a[k];
        if(t <= w) ans.insert(t);
    }
    cout << ans.size();
    return 0;
}