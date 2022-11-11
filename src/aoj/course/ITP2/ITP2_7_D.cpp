#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    multiset<int> ms;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int cmd, x, l, r;
        cin >> cmd;
        if (cmd == 3)
            cin >> l >> r;
        else
            cin >> x;

        if (cmd == 0) {
            ms.insert(x);
            cout << ms.size() << endl;
        }
        if (cmd == 1) {
            cout << ms.count(x) << endl;
        }
        if (cmd == 2) {
            ms.erase(x);
        }
        if (cmd == 3) {
            for (auto it = ms.lower_bound(l); it != ms.upper_bound(r); ++it) {
                cout << *it << endl;
            }
        }
    }

    return 0;
}
