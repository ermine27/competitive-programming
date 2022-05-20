#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;

int main(){
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int hit = 0, blow = 0;

    rep(i,n){
        rep(j,n){
            if(a[i] == b[j]){
                if(i==j) ++hit;
                else ++blow;
            }
        }
    }

    cout << hit << endl << blow;
}
