#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    bool ok = false;
    for (int i = a; i <= b; i++) {
        if (100 % i == 0)
            ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
