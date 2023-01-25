#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, k, ans;
    cin >> l >> k;
    ans = l / (k * 2);
    if (l % (k * 2) == 0)
        ans--;
    cout << ans * k << endl;
    return 0;
}
