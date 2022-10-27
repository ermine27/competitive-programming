/*
dequeを使ってランレングス圧縮を利用して解く
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
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using mii = map<int,int>;
using mil = map<int,ll>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }


int main() {
    int n, a, x, y, right;
    in(n);

    deque<pii> deq;

    repe(i, n) {
        in(a);

        if (i == 1) {
            deq.push_back(make_pair(a, 1));
            continue;
        }

        if (i % 2 == 1) {
            if (deq.back().first == a) {
                deq.back().second++;
            } else {
                deq.push_back(make_pair(a, 1));
            }
            right = a;
        } else {
            if (a == right) {
                deq.back().second++;
            } else {
                tie(x, y) = deq.back();
                deq.pop_back();
                if (!deq.empty()) {
                    int x2, y2;
                    tie(x2, y2) = deq.back();
                    deq.pop_back();
                    y += y2;
                }

                deq.push_back(make_pair(a, y + 1));
            }
        }
    }

    int ans = 0;
    while (deq.empty() == false) {
        tie(x, y) = deq.front();
        deq.pop_front();
        if (x == 0) ans += y;
    }

    out(ans);
    return 0;
}
