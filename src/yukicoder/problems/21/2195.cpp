#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> s;
    vector<int> cnt(30);

    while (q--) {
        int cmd, x;
        cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            if (s.count(x))
                continue;

            s.insert(x);
            bitset<30> bs(x);
            for (int i = 0; i < 30; i++) {
                if (bs[i])
                    cnt[i]++;
            }
        }
        if (cmd == 2) {
            cin >> x;
            if (!s.count(x))
                continue;

            s.erase(x);
            bitset<30> bs(x);
            for (int i = 0; i < 30; i++) {
                if (bs[i] && cnt[i])
                    cnt[i]--;
            }
        }
        if (cmd == 3) {
            int sz = (int)s.size();
            if (sz == 0) {
                cout << -1 << endl;
                continue;
            }

            long long res = 0;
            long long p = 1;
            for (int i = 0; i < 30; i++) {
                if (cnt[i] == sz)
                    res += p;
                p *= 2;
            }
            cout << res << endl;
        }
    }

    return 0;
}
