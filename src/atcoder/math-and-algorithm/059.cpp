#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    int a;
    cin >> n;
    m = n % 4;
    if (m == 1)
        a = 2;
    if (m == 2)
        a = 4;
    if (m == 3)
        a = 8;
    if (m == 0)
        a = 6;
    cout << a << endl;
    return 0;
}
