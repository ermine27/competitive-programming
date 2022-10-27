#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
using ll = long long;
using vi = vector<int>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main(){
    string s;
    in(s);
    s = '0' + s;

    if (s[1] == '1') {
        out("No");
        return 0;
    }

    vi row(7);
    if (s[7] == '1') row[0]++;
    if (s[4] == '1') row[1]++;
    if (s[2] == '1' || s[8] == '1') row[2]++;
    if (s[5] == '1') row[3]++;
    if (s[3] == '1' || s[9] == '1') row[4]++;
    if (s[6] == '1') row[5]++;
    if (s[10] == '1') row[6]++;

    string ans = "No";
    rep(i, 5) {
        rep(j, i + 1, 6) {
            rep(k, j + 1, 7) {
                if (row[i] && !row[j] && row[k]) ans = "Yes";
            }
        }
    }

    out(ans);
    return 0;
}
