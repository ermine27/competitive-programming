#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    bitset<32> bs(x);

    cout << bs << endl;
    cout << (~bs) << endl;
    cout << (bs << 1) << endl;
    cout << (bs >> 1) << endl;

    return 0;
}
