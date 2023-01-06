#include <bits/stdc++.h>
using namespace std;

template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }

int main() {
    int n, ans = 0;
    in(n);

    ans += n / 25;
    n %= 25;
    ans += n / 10;
    n %= 10;
    ans += n / 5;
    n %= 5;
    ans += n;

    out(ans);
    return 0;
}
