#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using vi = vector<int>;

int main() {
    int n,ai;
    cin >> n;
    vi a(n,0);

    rep(i,4*n-1){
        cin >> ai;
        ++a[ai-1];
    }
    rep(i,n){
        if(a[i] != 4) cout << i + 1;
    }

}
