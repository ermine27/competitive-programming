#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main(){
    int n;
    cin >> n;

    vector<vector<char>> g(n, vector<char>(n));

    rep(i,n) rep(j,n){
        char c;
        cin >> c;
        g[i][j]= c;
    }

    string ans;
    rep(i,n) ans += '0';

    rep(i,n){
        rep(j,n){
            rep(k,8){
                string st;
                rep(l,n) st += g[(i+n+dx[k]*l)%n][(j+n+dy[k]*l)%n];
                chmax(ans,st);
            }

        }
    }

    cout << ans << endl;
    return 0;
}
