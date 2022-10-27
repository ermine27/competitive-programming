#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
using vi = vector<int>;
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int TIMES = 86400;

int strTime2int(string s) {
    int time = 0;

    time += stoi(s.substr(0, 2)) * 3600;
    time += stoi(s.substr(3, 2)) * 60;
    time += stoi(s.substr(6, 2));

    return time;
}

int main() {
    int n;
    string s1, s2;
    int t1, t2;

    while (true) {
        in(n);
        if (n == 0) break;

        vi imos(TIMES, 0);

        rep(i, n) {
            in(s1, s2);
            t1 = strTime2int(s1);
            t2 = strTime2int(s2) - 1;

            ++imos[t1];
            if (t2 <= TIMES) {
                --imos[t2 + 1];
            }
        }

        int cur = 0, ans = 0;
        rep(i, TIMES) {
            cur += imos[i];
            chmax(ans, cur);
        }

        out(ans);
    }
    return 0;
}
