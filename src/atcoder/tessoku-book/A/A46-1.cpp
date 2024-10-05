/*
case1: 貪欲法

score: 4230
*/
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

int main(){
    int n;
    cin >> n;
    vi a(n), b(n), v(n);

    rep(i,n){
        cin >> a[i] >> b[i];
    }

    v[0] = 1;
    int cx=a[0],cy=b[0];
    cout << 1 << endl;

    rep(i,n){
        int mindist = 1e9;
        int nextno = 0;
        rep(j,n){
            if(v[j]==1) continue;
            int dist=(cx-a[j])*(cx-a[j])+(cy-b[j])*(cy-b[j]);
            if(chmin(mindist,dist)) {
                nextno = j;
            }
        }
        v[nextno]=1;
        cx = a[nextno];
        cy = b[nextno];
        cout << nextno+1 << endl;
    }

    return 0;
}
