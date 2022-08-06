#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using vi = vector<int>;

int main(){
    int n;
    cin >> n;
    vi p(n+1);
    reps(i, 2, n+1) cin >> p[i];

    int x = n;
    int ans = 0;
    while(x!=1){
        x = p[x];
        ++ans;
    }

    cout << ans;
    return 0;
}
