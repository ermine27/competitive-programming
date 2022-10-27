/*
編集距離（レーベンシュタイン距離 : Levenshtein distance）

*/
#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f

#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)

#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using vi = vector<int>;
using vvi = vector<vi>;


int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length(), l2 = s2.length();

    vvi dp(l1 + 1, vi(l2 + 1));
    repe(i, l1) dp[i][0] = i;
    repe(i, l2) dp[0][i] = i;

    repe(i, 1, l1) {
        repe(j, 1, l2) {
            int c = (s1[i - 1] == s2[j - 1] ? 0 : 1);
            dp[i][j] = min({
                dp[i - 1][j] + 1,     // 文字の削除
                dp[i][j - 1] + 1,     // 文字の挿入
                dp[i - 1][j - 1] + c  // 文字の置換
            });
        }
    }

    cout << dp[l1][l2] << endl;
    return 0;
}
