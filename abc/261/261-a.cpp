#include <bits/stdc++.h>
using namespace std;

int main(){
    int l1, r1, l2, r2, ans = 0;
    cin >> l1 >> r1 >> l2 >> r2;

    if (l2 <= l1) {
        if (r2 <= l1)
            ans = 0;
        else if (r2 <= r1)
            ans = r2 - l1;
        else
            ans = r1 - l1;
    } else if (l2 <= r1) {
        if (r2 <= r1)
            ans = r2 - l2;
        else
            ans = r1 - l2;
    }

    cout << ans << endl;
    return 0;
}
