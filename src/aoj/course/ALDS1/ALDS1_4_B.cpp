#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
using vi = vector<int>;


int main(){
    int n, q;
    cin >> n;
    vi s(n);
    rep(i,n) cin >> s[i];
    cin >> q;

    int ti, ans = 0;
    rep(i,q){
        cin >> ti;
        if(binary_search(all(s),ti)) ++ans;
    }

    cout << ans << endl;
    return 0;
}
