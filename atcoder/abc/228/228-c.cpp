#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using vi = vector<int>;


int main(){
    int n,k;
    cin >> n >> k;
    vi p(n,0);
    rep(i, n){
        rep(j, 3){
            int pij;
            cin >> pij;
            p[i] += pij;
        }
    }
    vi t = p;
    sort(all(t));
    reverse(all(t));

    int b = t[k-1];
    rep(i,n){
        if(p[i] + 300 >= b){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}
