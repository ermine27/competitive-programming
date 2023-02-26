#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    long long n;
    cin >> n;
    long long ss = n * (n + 1) / 2 % mod;
    cout << (ss * ss % mod) << endl;
    return 0;
}
