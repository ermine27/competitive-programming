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
    string t;
    cin >> n >> t;
    
    int x = 0, y = 0, quad = 0;
    rep(i,n){
        if(t[i] == 'R') quad = (quad + 1) % 4;
        else {
            if(quad == 0) ++x;
            if(quad == 1) --y;
            if(quad == 2) --x;
            if(quad == 3) ++y;
        }
    }

    cout << x << ' ' << y;
}