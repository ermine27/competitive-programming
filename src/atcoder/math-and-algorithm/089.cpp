#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    if (c == 1) {
        cout << "No" << endl;
        return 0;
    }

    long long v = 1;
    for (int i = 0; i < b; i++) {
        if (a / c < v) {
            cout << "Yes" << endl;
            return 0;
        }
        v *= c;
    }

    cout << "No" << endl;
    return 0;
}
