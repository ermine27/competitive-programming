#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;

int main(){
    int n, c;
    cin >> n >> c;

    int func1 = pow(2,30)-1;
    vi func = {0, func1};
    // 上記は以下のように書ける。（func1は32ビット全て1でも問題ない）
    // vi func = {0, ~0};

    rep(i,n){
        int t, a;
        cin >> t >> a;

        rep(d,2){
            if(t==1) func[d] &= a;
            if(t==2) func[d] |= a;
            if(t==3) func[d] ^= a;
        }

        int ans = 0;
        rep(j,30){
            int ci = (c & (1<<j) ? 1 : 0);
            ans += func[ci] & (1<<j);
        }
        cout << ans << endl;
        c = ans;

        // 上記の処理はループを使わずに行える
        // 各ビットの値が0ならNOTを取ってfunc0とのANDを取り、
        // 値が1ならfunc1とのANDを取れば0と1それぞれの変換ができるので、あとはそれをORでつなぐ
        // c = (func[0] & ~c) | (func[1] & c);
        // cout << c << endl;
    }

    return 0;
}
