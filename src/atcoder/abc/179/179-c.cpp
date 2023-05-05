#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int a = 1; a < n; a++) {
        // ループで書いても十分ACする
        // for(int b=1; a*b<n; b++){
        //     ans++;
        // }
        ans += (n - 1) / a;
    }
    cout << ans << endl;
    return 0;
}
