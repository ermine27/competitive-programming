#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define cout(x) cout<<(x)
#define couts(x) cout<<(x)<<' '
#define coutn(x) cout<<(x)<<endl
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pil = pair<int,ll>;


int main(){
    int m,n;
    cin >> m;
    vi sx(m), sy(m);
    rep(i,m){
        cin >> sx[i] >> sy[i];
    }

    cin >> n;
    vi x(n), y(n);
    set<pii> s;
    rep(i,n){
        cin >> x[i] >> y[i];
        s.insert(mp(x[i],y[i]));
    }

    rep(i,n){
        int xi = x[i];
        int yi = y[i];
        bool ok = true;
        reps(j,1,m){
            xi += sx[j] - sx[j-1];
            yi += sy[j] - sy[j-1];

            if(s.count(mp(xi,yi)) == 0){
                ok = false;
                break;
            }
        }

        if(ok == true){
            couts(x[i] - sx[0]);
            coutn(y[i] - sy[0]);
            return 0;
        }
    }
}
