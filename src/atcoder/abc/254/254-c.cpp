#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
#define pb push_back
#define cout(x) cout<<(x)
using vi = vector<int>;
using vvi = vector<vi>;


int main(){
    int n, k;
    cin >> n >> k;

    vvi d(k);
    rep(i,n){
        int ai;
        cin >> ai;
        d[i%k].pb(ai);
    }

    rep(i,k){
        sort(all(d[i]));
    }

    int pre = 0,cur = 0;
    bool ok = true;
    rep(i,n){
        pre = cur;
        cur = d[i%k][i/k];
        if(pre > cur){
            ok = false;
            break;
        }
    }

    cout(ok ? "Yes" : "No");
}
