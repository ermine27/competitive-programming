#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int d1, d2;
        cin >> d1 >> d2;
        if (cnt >= 3 || d1 == d2)
            cnt++;
        else
            cnt = 0;
    }
    cout << (cnt >= 3 ? "Yes" : "No") << endl;
    return 0;
}
