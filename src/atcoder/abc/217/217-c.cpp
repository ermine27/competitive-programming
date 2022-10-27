#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using vi = vector<int>;

int main() {
    int n;
    cin >> n;
    vi q(n);

    int pi;
    rep(i,n){
        cin >> pi;
        q[pi-1] = i + 1;
    }

    rep(i,n){
        cout << q[i];
        if(i < n - 1) cout << ' ';
    }
}