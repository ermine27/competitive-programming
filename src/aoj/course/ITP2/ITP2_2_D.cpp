#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<list<int>> l(n);
    for (int i = 0; i < q; ++i) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int t, x;
            cin >> t >> x;
            l[t].push_back(x);
        }
        if (cmd == 1) {
            int t;
            cin >> t;

            for (auto it = l[t].begin(); it != l[t].end(); ++it) {
                if (it != l[t].begin()) cout << ' ';
                cout << *it;
            }
            cout << endl;
        }
        if (cmd == 2) {
            int s, t;
            cin >> s >> t;
            l[t].splice(l[t].end(), l[s]);
            // 以下でも同じ動きをする
            // l[t].splice(l[t].end(), move(l[s]));
        }
    }

    return 0;
}
