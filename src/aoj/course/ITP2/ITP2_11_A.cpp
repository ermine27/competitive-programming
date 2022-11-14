#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 1 << n; ++i) {
        bitset<18> bs(i);
        cout << i << ':';
        for (int j = 0; j < n; ++j) {
            if (bs[j]) cout << ' ' << j;
        }
        cout << endl;
    }

    return 0;
}
