#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define exity(c) if(c){ cout << "Yes"; return 0; }
#define exitn(c) if(c){ cout << "No"; return 0; }

int main(){
    int n;
    cin >> n;
    vector<pair<double,double>> xy(n);
    int t1,t2;
    rep(i, n){
        cin >> t1 >> t2;
        xy[i] = make_pair(t1,t2);
    }

    sort(all(xy));

    int ans = 0;

    rep(i, n-2){ reps(j, i+1, n-1){ reps(k, j+1, n){

        double f1 = (xy[j].second - xy[i].second) / (xy[j].first - xy[i].first);
        double f2 = (xy[k].second - xy[j].second) / (xy[k].first - xy[j].first);

        if(f1 != f2) ++ans;

    } } }

    cout << ans;
}
