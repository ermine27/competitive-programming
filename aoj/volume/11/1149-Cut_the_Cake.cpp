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
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
template<typename... T> int in(T&... a){ (cin >> ... >> a); return 1; }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<typename T> void vecout(T& a){ int i=0; fore(v,a){ if(i>0){ cout << ' '; } ++i; cout << v; } cout << '\n'; }

struct rectangle {
    int top, bottom, left, right, area, width, depth, no;
    void Calculate() {
        width = right - left;
        depth = bottom - top;
        area = width * depth;
    }
};

int main() {
    int n, w, d;
    while (in(n, w, d) && !(n == 0 && w == 0 && d == 0)) {
        int p, s;
        rectangle r1, r2;

        vector<rectangle> rect;
        r1.top = 0;
        r1.bottom = d;
        r1.left = 0;
        r1.right = w;
        r1.no = 1;
        r1.Calculate();
        rect.push_back(r1);

        rep(i, n) {
            in(p, s);

            r1 = rect[p - 1];
            s %= r1.width + r1.depth;

            // 左上もしくは右下から何個先かを求める
            // 左上からと右下からで線を引く場所は変わるが、この問題では面積さえ求めればよく、
            // 線を引いたところでできる2つの長方形のそれぞれの面積は同じなので問題ない
            int cut = 1;
            if (s >= r1.width) {
                cut = 2;
                s -= r1.width;
            }

            r1.no = i + 1;
            r2 = r1;

            // 縦方向に切る
            if (cut == 1) {
                r1.right = r1.left + s;
                r2.left = r1.right;

            // 横方向に切る
            } else {
                r1.bottom = r1.top + s;
                r2.top = r1.bottom;
            }

            r1.Calculate();
            r2.Calculate();

            rect[p - 1] = r1;
            rect.push_back(r2);

            sort(all(rect), [](const rectangle& lhs, const rectangle& rhs) {
                if (lhs.no == rhs.no)
                    return lhs.area < rhs.area;
                else
                    return lhs.no < rhs.no;
            });
        }

        vi ans;
        fore(x, rect) { ans.push_back(x.area); }

        sort(all(ans));
        vecout(ans);
    }

    return 0;
}
