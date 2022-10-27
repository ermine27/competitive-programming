#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
    int n,m,ki,si,ans=0;
    cin >> n >> m;
    vi k(m);
    vvi s(m);
    vi p(n);
    rep(i,m){
        cin >> ki;
        k[i] = ki;
        rep(j,ki){
            cin >> si;
            s[i].push_back(si);
        }
    }
    rep(i,m) cin >> p[i];

    rep(i,1<<n){
        bitset<10> b = i;        
        bool ok = true;
        rep(j,m){
            int sum = 0;
            rep(k,s[j].size()) sum += b[s[j][k]-1]; 
            if(sum % 2 != p[j]){
                ok = false;
                break;
            }
        }
        if(ok) ++ans;
    }
    cout << ans;
}
