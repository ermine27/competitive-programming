#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& x:a)
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;

// 点数を計算する
ll getScore(string s){
    vi score(10);
    iota(all(score),0);
    rep(i,5) score[s[i]-'0'] *= 10;
    return accumulate(all(score),0);
}

int main(){
    int k;
    string s,t;
    cin >> k >> s >> t;

    // 各数字があと何個残っているかを持っておく（K-s,tで使われている数）
    vl cnt(10,k);
    fore(c, s+t) --cnt[c-'0'];

    ll win=0;
    reps(i,1,10){
        reps(j,1,10){
            // string.back() で最後の文字にアクセスし、値を更新する
            s.back() = '0' + i;
            t.back() = '0' + j;
            if(getScore(s) <= getScore(t)) continue;

            // (i,j)の組み合わせがいくつかるか
            // 5枚目の手札は2枚だけなので、以下のように計算すれば残りの枚数が1枚または0枚の時は積が0になる
            if(i==j){
                win += cnt[i] * (cnt[j] - 1);
            } else {
                win += cnt[i] * cnt[j];
            }
        }
    }

    // 全ての組み合わせの数を計算
    ll remains = 9*k-8;
    ll total = remains * (remains - 1);

    // 求める答え＝高橋くんの勝つ数／全ての組み合わせの数
    double ans = 1.0 * win / total;

    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}
