#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, ans;
    cin >> a >> b;
    ans = b / a;
    if (b % a != 0)
        ans++;
    cout << ans << endl;
    return 0;
}
