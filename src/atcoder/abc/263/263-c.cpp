
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define sz(x) ((int)(x).size())
using vi = vector<int>;

int n, m;

void dfs(vi a, int x){
    a.push_back(x);

    if(sz(a) >= n){
        rep(i,n){
            if(i>0) cout << ' ';
            cout << a[i];
        }
        cout << endl;
        return;
    }

    reps(i,x+1,m+1){
        dfs(a, i);
    }
}

int main(){
    cin >> n >> m;

    repf(i,m){
        dfs({},i);
    }

    return 0;
}
