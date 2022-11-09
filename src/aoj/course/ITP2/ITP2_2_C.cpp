#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<priority_queue<int>> pq(n);
    for (int i = 0; i < q; ++i) {
        int cmd, t;
        cin >> cmd >> t;

        if (cmd == 0) {
            int x;
            cin >> x;
            pq[t].emplace(x);
        }

        if (pq[t].empty() == true) continue;

        if (cmd == 1) {
            cout << pq[t].top() << endl;
        }
        if (cmd == 2) {
            pq[t].pop();
        }
    }

    return 0;
}
