#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define npos string::npos
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;


int main(){
    int n;    
    cin >> n;
    vi a(n,0);
    int ci;
    rep(i,n){
        cin >> ci;
        a[ci] = 1;
    }

    ci = 0;
    while(a[ci] == 1){
        ++ci;
    }

    cout << ci;
}
