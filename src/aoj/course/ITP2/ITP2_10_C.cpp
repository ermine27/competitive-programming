#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, cmd, i;
    cin >> q;
    bitset<64> bs;

    for (int j = 0; j < q; ++j) {
        cin >> cmd;
        if (cmd < 4) cin >> i;

        if (cmd == 0) cout << bs.test(i) << endl;
        if (cmd == 1) bs.set(i);
        if (cmd == 2) bs.reset(i);
        if (cmd == 3) bs.flip(i);
        if (cmd == 4) cout << bs.all() << endl;
        if (cmd == 5) cout << bs.any() << endl;
        if (cmd == 6) cout << bs.none() << endl;
        if (cmd == 7) cout << bs.count() << endl;
        if (cmd == 8) cout << bs.to_ullong() << endl;  // to_ullong: bitsetから整数へ変換する
    }

    return 0;
}
