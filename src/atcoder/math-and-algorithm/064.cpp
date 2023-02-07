#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a, an = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        an += a;
    }

    cout << (an <= k && (k - an) % 2 == 0 ? "Yes" : "No") << endl;
    return 0;
}