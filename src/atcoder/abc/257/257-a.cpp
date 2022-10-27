#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    int n, x;
    cin >> n >> x;
    string s;

    rep(i,26){
        char c = 'A' + i;
        rep(j,n){
            s += c;
        }
    }

    cout << s[x-1];

    return 0;
}
