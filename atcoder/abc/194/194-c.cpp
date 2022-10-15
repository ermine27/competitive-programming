#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

int main(){
    int n;
    cin >> n;

    map<int,int> a;
    int ai;
    rep(i,n){
        cin >> ai;
        a[ai]++;
    }
    ll ans = 0;
    fore(x,a){
        fore(y,a){
            if(x.first == y.first) continue;
            ans += pow(x.first - y.first, 2) * x.second * y.second;
        }
    }

    cout << ans / 2;
}