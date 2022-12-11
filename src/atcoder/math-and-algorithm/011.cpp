#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << 2;
    for (int i = 3; i <= n; i++) {
        bool ok = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0)
                ok = false;
        }
        if (ok) {
            cout << ' ' << i;
        }
    }
    cout << endl;
    return 0;
}
