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
    int n;
    cin >> n;
    vl t(n), k(n);
    vvi a;
    rep(i,n){
        cin >> t[i] >> k[i];
        vi ai;
        ai.push_back(-1);
        int aij;
        rep(j, k[i]){
            cin >> aij;
            --aij;
            ai.push_back(aij);
        }
        a.push_back(ai);
    }

    queue<int> q;
    set<int> s;
    q.push(n-1);
    s.insert(n-1);
    while(q.empty() == false){
        int qi = q.front();
        q.pop();
        rep(i,k[qi]+1){
            int qij = a[qi][i];
            if(qij == -1) continue;

            if(s.count(qij) == false){
                s.insert(qij);
                q.push(qij);
            }
        }
    }

    ll ans = 0;
    fore(x,s) ans += t[x];

    cout << ans;
}