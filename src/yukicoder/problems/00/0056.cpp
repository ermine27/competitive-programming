#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, tax;
    double p;
    cin >> d >> p;
    tax = d * p / 100;
    cout << d + tax << endl;
    return 0;
}
