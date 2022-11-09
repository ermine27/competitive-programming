#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<queue<int>> que(n);
    for (int i = 0; i < q; ++i) {
        int cmd, t;
        cin >> cmd >> t;

        if (cmd == 0) {
            int x;
            cin >> x;
            que[t].emplace(x);
        }

        if (que[t].empty() == true) continue;

        if (cmd == 1) {
            cout << que[t].front() << endl;
        }
        if (cmd == 2) {
            que[t].pop();
        }
    }

    return 0;
}
