#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
            long long j = n / i;
            if (j != i) {
                cout << j << endl;
            }
        }
    }
    return 0;
}
