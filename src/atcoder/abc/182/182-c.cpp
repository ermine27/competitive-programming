#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ns = s.length();
    int ans = 99;

    for (int i = 1; i < 1 << ns; i++) {
        bitset<18> bs(i);
        int t = ns - bs.count();

        int c = 0;
        for (int j = 0; j < ns; j++) {
            if (bs[j])
                c += s[j] - '0';
        }
        if (c % 3 == 0 && t < ans)
            ans = t;
    }

    cout << (ans == 99 ? -1 : ans) << endl;
    return 0;
}
