#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    set<int> s;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int cmd, x, l, r;
        cin >> cmd;
        if (cmd == 3)
            cin >> l >> r;
        else
            cin >> x;

        if (cmd == 0) {
            s.insert(x);
            cout << s.size() << endl;
        }
        if (cmd == 1) {
            cout << (s.find(x) != s.end() ? 1 : 0) << endl;
        }
        if (cmd == 2) {
            s.erase(x);
        }
        if (cmd == 3) {
            auto itl = s.lower_bound(l);
            auto itr = s.upper_bound(r);
            for (auto it = itl; it != itr; ++it) {
                cout << *it << endl;
            }
        }
    }

    return 0;
}
