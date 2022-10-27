#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    int max = 0;
    rep(i, n){
        int ai;
        cin >> ai;
        a[i] = ai;
        chmax(max, ai);
    }
    vi maxi;
    rep(i,n){
        if(a[i] == max) maxi.push_back(i);
    }
    bool hate = false;
    rep(i,k){
        int bi;
        cin >> bi;
        --bi;
        fore(mi, maxi){
            if(mi == bi) hate = true;
        }
    }

    cout << (hate ? "Yes" : "No");
}

