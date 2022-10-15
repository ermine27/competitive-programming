#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;

const int NIL = -1;

vi pre, in, post;
int pos = 0;

void reconstruction(int l, int r){
    if(l >= r) return;

    int root = pre[pos];
    ++pos;
    int m = l;
    while(in[m] != root) ++m;
    reconstruction(l, m);
    reconstruction(m+1, r);
    post.push_back(root);
}

int main(){
    int n;
    cin >> n;
    pre.resize(n);
    in.resize(n);
    rep(i,n) cin >> pre[i];
    rep(i,n) cin >> in[i];

    reconstruction(0, n);

    rep(i,n){
        if(i != 0) cout << ' ';
        cout << post[i];
    }
    cout << endl;

    return 0;
}
