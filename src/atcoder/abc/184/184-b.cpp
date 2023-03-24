#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    string s;
    cin >> n >> x >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            x = max(0, x - 1);
        } else {
            x++;
        }
    }
    cout << x << endl;
    return 0;
}
