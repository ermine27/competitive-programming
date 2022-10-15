#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;


int main() {
    int h,w;
    vvi a;
    cin >> h >> w;
    a.resize(h,vector<int>(w));

    rep(i,h) rep(j,w) cin >> a[i][j];

    rep(i,w) {
        rep(j,h){
            cout << a[j][i];
            if(j < h-1) cout << ' ';
            if(i != w-1 && j == h-1) cout << endl;
        }
    }

}