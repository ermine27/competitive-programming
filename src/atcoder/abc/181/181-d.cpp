#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
    int slen = s.length();

    if (slen == 1) {
        return s == "8";
    }

    if (slen == 2) {
        string s2 = {s[1], s[0]};
        return stoi(s) % 8 == 0 || stoi(s2) % 8 == 0;
    }

    vector<int> a(10);
    for (int i = 0; i < slen; i++) {
        a[s[i] - '0']++;
    }

    for (int k = 104; k < 1000; k += 8) {
        int j = k;
        vector<int> c(10);
        while (j > 0) {
            c[j % 10]++;
            j /= 10;
        }

        bool ok = true;
        for (int i = 0; i < 10; i++) {
            if (a[i] < c[i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            return true;
    }

    return false;
}

int main() {
    string s;
    cin >> s;
    cout << (solve(s) ? "Yes" : "No") << endl;
    return 0;
}
