#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[s.length() - 1] == 's')
        s += 'e';
    s += 's';
    cout << s << endl;
    return 0;
}
