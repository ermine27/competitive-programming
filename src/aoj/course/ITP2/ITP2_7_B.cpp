#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    set<int> s;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int cmd, x;
        cin >> cmd >> x;

        if (cmd == 0) {
            s.insert(x);
            cout << s.size() << endl;
        }
        if (cmd == 1) {
            cout << (s.find(x) != s.end() ? 1 : 0) << endl;
        }
        if (cmd == 2) {
            s.erase(x);
        }
    }

    return 0;
}
