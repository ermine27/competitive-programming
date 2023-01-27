#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1, 1);
    p[0] = p[1] = 0;

    for (int i = 2; i * i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            p[j] = 0;
        }
    }

    vector<int> pm;
    for (int i = 2; i <= n; i++) {
        if (p[i])
            pm.push_back(i);
    }

    vector<int> win(n + 1, 0);
    win[0] = win[1] = 1;
    for (int i = 2; i <= n; i++) {
        int k = i;

        for (int x : pm) {
            if (x >= k)
                break;
            if (!win[k - x]) {
                win[i] = 1;
            }
        }
    }

    cout << (win[n] ? "Win" : "Lose") << endl;
    return 0;
}
