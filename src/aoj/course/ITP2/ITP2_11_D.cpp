#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 1 << n; ++i) {
        bitset<18> bs(i);
        int no = 0;

        if ((int)bs.count() != k) continue;

        for (int j = 0; j < n; ++j) {
            if (bs[j]) no += 1 << j;
        }
        cout << no << ':';

        for (int j = 0; j < n; ++j) {
            if (bs[j]) cout << ' ' << j;
        }
        cout << endl;
    }

    return 0;
}
