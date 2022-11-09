#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<stack<int>> st(n);
    for (int i = 0; i < q; ++i) {
        int cmd, t;
        cin >> cmd >> t;
        if (cmd == 0) {
            int x;
            cin >> x;
            st[t].push(x);
        }

        if (st[t].empty() == true) continue;

        if (cmd == 1) {
            cout << st[t].top() << endl;
        }
        if (cmd == 2) {
            st[t].pop();
        }
    }

    return 0;
}
