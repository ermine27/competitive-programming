#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define exity(c) if(c){ cout << "Yes"; return 0; }
#define exitn(c) if(c){ cout << "No"; return 0; }
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main(){
    int n,m;
    cin >> n >> m;
    vi b1(m), b2(m);

    rep(i,n){
        rep(j,m){
            cin >> b2[j];
            --b2[j];
        }

        rep(j,m-1) exitn(b2[j] + 1 != b2[j+1])

        if(i == 0 && m > 1){
            exitn(b2[0] % 7 > b2[1] % 7 || b2[m-2] % 7 > b2[m-1] % 7)
        }

        if(i > 0){
            rep(j,m) exitn(b1[j] + 7 != b2[j])
        }
        
        b1 = b2;
    }

    exity(1);
}