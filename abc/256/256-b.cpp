#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define per(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define perf(i,n) for(int i = (int)(n); i > 0; --i)
using vi = vector<int>;


int main(){
    int n, ai;
    cin >> n;

    vi m(4);
    int ans = 0;
    rep(i, n){
        cin >> ai;

        m[0] = 1;
        per(i,4){
            if(m[i]){
                if(i+ai > 3){
                    m[i] = 0;
                    ++ans;
                } else {
                    m[i+ai] = 1;
                    m[i] = 0;
                }
            }
        }

    }

    cout << ans;
    return 0;
}
