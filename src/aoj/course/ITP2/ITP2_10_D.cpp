#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, cmd, i, m;
    cin >> n;
    vector<bitset<64>> mask(n);
    for (int j = 0; j < n; ++j) {
        int k, b;
        cin >> k;
        for (int l = 0; l < k; ++l) {
            cin >> b;
            mask[j].set(b);
        }
    }

    bitset<64> bs;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        cin >> cmd;
        if (cmd == 0)
            cin >> i;
        else
            cin >> m;

        if (cmd == 0) cout << bs.test(i) << endl;
        if (cmd == 1) bs |= mask[m];
        if (cmd == 2) bs &= ~mask[m];
        if (cmd == 3) bs ^= mask[m];
        if (cmd == 4) cout << (bs | ~mask[m]).all() << endl;
        if (cmd == 5) cout << (bs & mask[m]).any() << endl;
        if (cmd == 6) cout << (bs & mask[m]).none() << endl;
        if (cmd == 7) cout << (bs & mask[m]).count() << endl;
        if (cmd == 8) cout << (bs & mask[m]).to_ullong() << endl;
    }

    return 0;
}
