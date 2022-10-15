#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    rep(i,n) rep(j,n) cin >> a[i][j];

    bool ok = true;
    rep(i, n - 1) {
        reps(j, i + 1, n) {
            char c1, c2;
            c1 = a[i][j];
            c2 = a[j][i];

            if (c1 == 'W' && c2 != 'L') ok = false;
            if (c1 == 'L' && c2 != 'W') ok = false;
            if (c1 == 'D' && c2 != 'D') ok = false;
        }
    }

    cout << (ok ? "correct" : "incorrect") << endl;
    return 0;
}
