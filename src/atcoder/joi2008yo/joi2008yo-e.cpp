#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using vvi = vector<vi>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int r, c;
    cin >> r >> c;
    vvi a(r, vi(c));
    rep(i,r) rep(j,c) cin >> a[i][j];

    int ans = 0;
    rep(i,1<<r){
        bitset<10> bs = i;
        vvi b = a;

        rep(i,r){
            if(bs[i]){
                rep(j,c){
                    b[i][j] = 1 - b[i][j];
                }
            }
        }

        int sum = 0;
        rep(i,c){
            int ct = 0;
            rep(j,r){
                if(b[j][i]) ++ct;
            }
            sum += max(ct, r - ct);
        }

        chmax(ans, sum);
    }

    cout << ans << endl;
}
