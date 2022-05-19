#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define npos string::npos
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;


int main(){
    int h,w;
    cin >> h >> w;
    vvi grid(h, vi(w,0));  // 1:#, 0:.
    char c;
    rep(i,h) rep(j,w){
        cin >> c;
        if(c == '#') grid[i][j] = 1;
    }

    vvi step(h, vi(w,0));
    step[0][0] = 1;
    const int mx[2] = {1,0};
    const int my[2] = {0,1};
    int ans = 1;

    queue<pii> q;
    q.push(make_pair(0,0));
    while(q.empty() == false){
        pii cur = q.front();
        q.pop();

        int ch = cur.first;
        int cw = cur.second;
        int cs = step[ch][cw] + 1;

        rep(i,2){
            int nh = ch + mx[i];
            int nw = cw + my[i];

            if(nh < h && nw < w && grid[nh][nw] == 0 && step[nh][nw] == 0){
                step[nh][nw] = cs;
                chmax(ans,cs);
                q.push(make_pair(nh,nw));
            }
        }
    }

    cout << ans;
}
