#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vi t(n);
    rep(i,n) cin >> s[i] >> t[i];

    map<string,pii> sub;
    rep(i,n){
        if(sub.count(s[i]) == 0){
            sub[s[i]] = make_pair(t[i], i+1);
        }
    }

    int maxt = 0;
    int mini = n;
    fore(x, sub){
        int ti,i;
        tie(ti,i) = x.second;
        if(ti >= maxt){
            if(ti > maxt){
                maxt = ti;
                mini = i;
            } else {
                chmin(mini, i);
            }
        }
    }

    cout << mini;

    return 0;
}
