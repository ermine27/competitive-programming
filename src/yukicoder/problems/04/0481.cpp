#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 10;
    for (int i = 1; i <= 9; i++) {
        int b;
        cin >> b;
        if (b != i) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
