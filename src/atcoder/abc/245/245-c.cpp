#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()


int main(){
    ll n,k;
    vl a,b;
    cin >> n >> k;
    a.resize(n);
    b.resize(n);    
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    bool da, db, ba, bb;
    da = true, db = true;

    reps(i, 1, n){
        ba = da;  bb = db;
        da = false;
        db = false;

        if(ba == true){
            if(abs(a[i-1]-a[i]) <= k) da = true;
            if(abs(a[i-1]-b[i]) <= k) db = true;
        }
        if(bb == true){
            if(abs(b[i-1]-a[i]) <= k) da = true;
            if(abs(b[i-1]-b[i]) <= k) db = true;
        }

        if(da == false && db == false){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}
