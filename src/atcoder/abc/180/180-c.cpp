#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    set<long long> ans;
    ans.insert(1);
    ans.insert(n);
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans.insert(i);
            ans.insert(n / i);
        }
    }

    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
