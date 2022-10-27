#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
using ll = long long;


int main(){
    int n;
    cin >> n;

    vector<pair<double,double>> lr(n);
    int ti;
    double li, ri;
    rep(i,n){
        cin >> ti >> li >> ri;
        if(ti == 2 || ti == 4) ri -= 0.1;
        if(ti == 3 || ti == 4) li += 0.1;
        lr[i] = make_pair(li, ri);
    }

    ll ans = 0;
    rep(i, n-1){
        reps(j, i+1, n){
            if(! (lr[i].second < lr[j].first || lr[j].second < lr[i].first) )
                ++ans;
        }
    }
    cout << ans;

}
