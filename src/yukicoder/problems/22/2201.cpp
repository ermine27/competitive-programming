#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> ans;
    for (int i = 0; i < (1 << 8); i++) {
        string t = s;
        bitset<8> bs = i;

        for (int j = 0; j < 8; j++) {
            if (bs[j]) {
                if (t[j] == 'l' || t[j] == 'o')
                    t[j] = '1';
                if (t[j] == 'a' || t[j] == 's')
                    t[j] = '$';
            }
        }

        bool al = false, nm = false, sy = false;
        for (int j = 0; j < 8; j++) {
            if (islower(t[j]))
                al = true;
            else if (isdigit(t[j]))
                nm = true;
            else
                sy = true;
        }
        if (al && nm && sy) {
            ans.insert(t);
        }
    }

    cout << ans.size() << endl;
}
