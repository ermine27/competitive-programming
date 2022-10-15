#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    cout << ((n >= pow(2,31) * -1 && n < pow(2,31)) ? "Yes" : "No");
}