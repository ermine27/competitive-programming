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
    int n,q;
    cin >> n >> q;
    vvi r(n);
    int ai, bi, ci, di;
    rep(i,n-1){
        cin >> ai >> bi;
        --ai; --bi;
        r[ai].push_back(bi);
        r[bi].push_back(ai);
    }

    vi p(n,-1);
    p[0] = 0;

    queue<int> que;
    que.push(0);

    while(que.empty() == false){
        int cur = que.front();
        que.pop();
        fore(x, r[cur]){
            if(p[x] == -1){
                p[x] = p[cur] + 1;
                que.push(x);
            }
        }
    }

    rep(i,q){
        cin >> ci >> di;
        --ci; --di;

        if(p[ci] % 2 == p[di] % 2){
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }

}