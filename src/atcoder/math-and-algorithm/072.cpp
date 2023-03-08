#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int c = b; c > 0; c--) {
        if (b / c - (a - 1) / c >= 2) {
            cout << c << endl;
            return 0;
        }
    }
    return 0;
}
