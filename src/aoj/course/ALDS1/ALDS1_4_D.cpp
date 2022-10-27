#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;

int n,k;
vi w;


bool check(int p){
    int i = 0;
    int c = k;
    int s = 0;

    while(i < n && c > 0){
        while(i < n && s + w[i] <= p){
            s += w[i];
            ++i;
        }
        s = 0;
        --c;
    }
    return i == n ? true : false;
}


int main(){
    cin >> n >> k;
    w.resize(n);
    rep(i,n) cin >> w[i];

    ll ok = 1000000000;
    ll ng = -1;
    ll mid;

    while(abs(ok-ng) > 1){
        mid = (ok+ng) / 2;
        if(check(mid)){
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
}
