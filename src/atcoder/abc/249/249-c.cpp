#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main(){
    int n,k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int ans = 0;
    rep(i,1<<n){
        bitset<15> b = i;
        vi alphabet(26,0);

        rep(j,n){
            if(b[j]){
                rep(k, s[j].length()){
                    alphabet[s[j][k] - 'a']++;
                }
            }
        }

        int ct = 0;
        rep(j,26){
            if(alphabet[j] == k) ++ct;
        }

        chmax(ans,ct);
    }

    cout << ans;
}
