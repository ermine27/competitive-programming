/*
考え方

Nが10^6あるので計算量はO(n log n)くらいまでに収める必要がある

計算過程で10^18を超えることがあるので、愚直に計算を繰り返していくことはできない

木構造で考えるのではなく、移動を圧縮することを考えたい
　LUとRUは何もしないことと変わらない
　これを消していく事を考えるが、str.find()の計算量はO(n)　→　loopの中で回すと計算量がオーバーする

解き方としては、後ろから読み込んでUが出たら次のLRを消して圧縮する
(スタック使ってもできそう)

圧縮後の文字列について、順番に実行して最終の値を出力することで実行時間制限内に処理が終えられる。
　
*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define all(v) v.begin(), v.end()
using ll = long long;


int main(){
    ll n,x;
    string s;
    cin >> n >> x >> s;

    reverse(all(s));
    string sr;
    int cu = 0, cl = 0, cr = 0;

    rep(i,n){
        if(s[i] == 'U'){
            ++cu;
        } else {
            if(cu > 0) --cu;
            else sr += s[i];
        }
    }
    rep(i,cu) sr += 'U';

    reverse(all(sr));

    rep(i,sr.size()){
        char c = sr[i];
        if(c == 'U') x /= 2;
        if(c == 'L') x *= 2;
        if(c == 'R') x = x * 2 + 1;
    }

    cout << x;
    return 0;
}
