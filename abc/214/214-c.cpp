#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n;
    cin >> n;
    vi s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];

    int min_no = 0, min_val = INT_MAX;
    rep(i,n) if(chmin(min_val, t[i])) min_no = i;

    rep(i, n-1){
        int j = (min_no + i) % n;
        int next_no = (j+1) % n;

        if(t[next_no] < min_val + s[j]) min_val = t[next_no];
        else {
            min_val += s[j];
            t[next_no] = min_val;
        }
    }

    rep(i,n) cout << t[i] << endl;
}

