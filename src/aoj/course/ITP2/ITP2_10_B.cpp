#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    bitset<32> bsa(a), bsb(b);

    cout << (bsa & bsb) << endl;
    cout << (bsa | bsb) << endl;
    cout << (bsa ^ bsb) << endl;

    return 0;
}
