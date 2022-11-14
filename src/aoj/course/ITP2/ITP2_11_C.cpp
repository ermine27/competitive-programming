#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> b(k);
    for (int i = 0; i < k; ++i) cin >> b[i];

    for (int i = 0; i < 1 << k; ++i) {
        bitset<18> bs(i);
        int no = 0;

        for (int j = 0; j < k; ++j) {
            if (bs[j]) no += 1 << b[j];
        }
        cout << no << ':';

        for (int j = 0; j < k; ++j) {
            if (bs[j]) cout << ' ' << b[j];
        }
        cout << endl;
    }

    return 0;
}
