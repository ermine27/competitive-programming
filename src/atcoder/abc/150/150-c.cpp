#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
using vi = vector<int>;


int main() {
    int n,pc,qc;
    cin >> n;
    vi p(n),q(n),c(n);

    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    iota(all(c), 1);

    int ct = 0;
    do{
        ++ct;
        if(c == p) pc = ct;           
        if(c == q) qc = ct;

    }while(next_permutation(all(c)));

    cout << abs(pc-qc);
}
