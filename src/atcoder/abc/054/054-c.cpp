#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
using vi = vector<int>;

int main() {
    int n,m,ai,bi,ans=0;
    cin >> n >> m;
    vector<pair<int,int>> ab(m);

    rep(i,m){
        cin >> ai >> bi;
        ab[i] = make_pair(ai,bi);
    }
    vi c(n);
    iota(all(c), 1);

    do{
        if(c[0] != 1) continue;

        bool ok = true;
        rep(i,n-1){
            int c1=c[i], c2=c[i+1];
            if(c1>c2) swap(c1,c2);
            pair<int,int> abi = make_pair(c1,c2);

            bool ok2 = false;
            for(auto e:ab){
                if(e == abi){
                    ok2 = true;
                }
            }

            if(!ok2) ok = false;
        }
        if(ok) ++ans;

    }while(next_permutation(all(c)));

    cout << ans;
}