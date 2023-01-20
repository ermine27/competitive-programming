#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << "Drew" << endl;
    }
    if ((n + 1) % 3 == k) {
        cout << "Won" << endl;
    }
    if (n == (k + 1) % 3) {
        cout << "Lost" << endl;
    }
    return 0;
}
