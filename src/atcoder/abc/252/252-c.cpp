#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using vvi = vector<vi>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n;
    cin >> n;

    vvi dec(10, vector<int>(10));

    rep(i, n){
        string s;
        cin >> s;
        rep(j,10){
            dec[(int)(s[j] - '0')][j]++;
        }
    }

    int ans = 1e6;

    rep(i,10){
        int time = 0;
        int ct = n;

        while(true){
            int t2 = time % 10;
            if(dec[i][t2] > 0){
                dec[i][t2]--;
                --ct;
                if(ct == 0) break;
            }
            ++time;
        }

        chmin(ans, time);
    }

    cout << ans;
}
