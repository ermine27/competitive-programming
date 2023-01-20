#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        bool ok = false;
        if (i % 3 == 0)
            ok = true;

        string str = to_string(i);
        if (find(str.begin(), str.end(), '3') != str.end())
            ok = true;

        if (ok)
            cout << i << endl;
    }
    return 0;
}
