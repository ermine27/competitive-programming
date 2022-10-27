#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
#define all(v) v.begin(), v.end()
using vi = vector<int>;

int main(){
    vi c(5);
    rep(i,5) cin >> c[i];
    sort(all(c));

    // if(c[0] == c[1] && c[1] == c[2] && c[2] != c[3] && c[3] == c[4]){
    //     cout << "Yes";
    // } else if(c[0] == c[1] && c[1] != c[2] && c[2] == c[3] && c[3] == c[4]){
    //     cout << "Yes";
    // } else {
    //     cout << "No";
    // }

    // ソート済であることから、同じ数が書かれたカード3枚の判定は両端のみでよい。
    // また、制約に「A,B,C,D,E 全てが同じ値ではない」とあるので、この場合の考慮はいらない。
    // まとめると、以下の内容で十分である。
    if((c[0] == c[2] && c[3] == c[4]) || (c[0] == c[1] && c[2] == c[4])){
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
