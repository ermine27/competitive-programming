#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x = 1;
    cin >> n;
    while (x <= n) {
        x *= 2;
        if (x - 1 == n) {
            cout << "Second" << endl;
            return 0;
        }
    }
    cout << "First" << endl;
    return 0;
}
