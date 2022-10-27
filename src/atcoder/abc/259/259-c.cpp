#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define fore(x, a) for (auto &x : a)
#define sz(x) ((int)(x).size())

string s, t;
vector<pair<char, int>> ps, pt;

void runLengthEncoding(string &x, vector<pair<char, int>> &px) {
    char pre = '#';
    int chain = 0;
    fore(c, x) {
        if (c == pre) {
            ++chain;
        } else {
            if (pre != '#') {
                px.push_back(make_pair(pre, chain));
            }
            pre = c;
            chain = 1;
        }
    }
    px.push_back(make_pair(pre, chain));
}

int main() {
    cin >> s >> t;

    runLengthEncoding(s, ps);
    runLengthEncoding(t, pt);

    if (ps.size() != pt.size()) {
        cout << "No";
        return 0;
    }

    rep(i, sz(ps)) {
        if (ps[i].first != pt[i].first) {
            cout << "No";
            return 0;
        }

        int cs = ps[i].second;
        int ct = pt[i].second;
        if (cs > ct || (cs < ct && cs < 2)) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}
