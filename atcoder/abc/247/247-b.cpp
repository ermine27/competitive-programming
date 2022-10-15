#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i] >> t[i];

    rep(i,n){
        bool ok1 = true, ok2 = true;
        rep(j,n){
            if(i==j) continue;

            if(s[i] == s[j] || s[i] == t[j]) ok1 = false;
            if(t[i] == t[j] || t[i] == s[j]) ok2 = false;
        }
        if(ok1 == false && ok2 == false){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}
