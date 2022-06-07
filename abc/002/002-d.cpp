#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n, m;
    cin >> n >> m;
    set<pii> p;
    rep(i, m){
        int xi,yi;
        cin >> xi >> yi;
        --xi; --yi;
        p.insert(make_pair(xi,yi));
    }

    int ans = 1;
    rep(i, 1<<n){
        bitset<12> bs = i;
        vi u;
        rep(j,n){
            if(bs[j]) u.push_back(j);
        }
        int usize = u.size();

        bool ok = true;
        rep(j,usize-1){
            reps(k,j+1,usize){
                if(p.count(make_pair(u[j],u[k])) == 0){
                    ok = false;
                }
            }
        }

        if(ok){
            chmax(ans, usize);
        }
    }

    cout << ans << endl;
}
