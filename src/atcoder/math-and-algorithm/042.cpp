/*
参考
https://crieit.net/posts/koya-abc172-d
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> divisorCountTable(int x) {
    vector<int> primes(x + 1, 1);

    for (int i = 2; i <= x; ++i) {
        for (int j = i; j <= x; j += i) {
            primes[j]++;
        }
    }

    return primes;
}

int main() {
    int x;
    cin >> x;
    vector<int> d = divisorCountTable(x);

    long long ans = 0;
    for (int i = 1; i <= x; i++) {
        ans += 1LL * i * d[i];
    }

    cout << ans << endl;
    return 0;
}
