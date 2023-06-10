#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

/*
最初に考えた解法
Ai<=100 と値が小さいので、1人部屋～100人部屋が何番目にあるかを持っておき、
毎回100人部屋から順番に1～Li,Ri～N番目の中にあるかを探していく。
*/
#if 0
int main() {
    int n, d;
    cin >> n;
    vector<vi> c(101);
    rep(i, n) {
        int a;
        cin >> a;
        c[a].push_back(i);
    }

    cin >> d;
    rep(i, d) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        for (int j = 100; j > 0; j--) {
            if (c[j].size() > 0 && (*c[j].begin() < l || *c[j].rbegin() > r)) {
                cout << j << endl;
                break;
            }
        }
    }

    return 0;
}
#endif

/*
想定解法
工事する区間の左側で最も大きい部屋と右側で最も大きい部屋の大きい方が答えになるので、
これを毎回都度順番に調べなくてもいいようにする。
予め、左から1番目まで、2番目まで、、、n番目までの中で最も大きい部屋と、
右から1番目まで、2番目まで、、、n番目までの中で最も大きい部屋の情報を持っておけば O(N) の計算量で求まる。
*/
int main() {
    int n, d;
    cin >> n;
    vi a(n+2), lt(n+2), rt(n+2);
    rep(i, n) {
        cin >> a[i+1];
    }

    for(int i=1; i<=n; i++){
        lt[i] = max(lt[i-1], a[i]);
    }
    for(int i=n; i>0; i--){
        rt[i] = max(rt[i+1], a[i]);
    }

    cin >> d;
    rep(i, d) {
        int l, r;
        cin >> l >> r;
        cout << max(lt[l-1], rt[r+1]) << endl;
    }

    return 0;
}
