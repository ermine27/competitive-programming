#include <bits/stdc++.h>
using namespace std;

template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main(){
    string s;
    in(s);
    int ans;

    if (s == "Monday") ans = 5;
    if (s == "Tuesday") ans = 4;
    if (s == "Wednesday") ans = 3;
    if (s == "Thursday") ans = 2;
    if (s == "Friday") ans = 1;

    out(ans);
    return 0;
}
