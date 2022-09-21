#include <bits/stdc++.h>
using namespace std;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int a, b, c, d, ans;
    in(a, b, c, d);
    ans = (a + b) * (c - d);
    out(ans);
    out("Takahashi");
    return 0;
}
