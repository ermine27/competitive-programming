#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v, w;
    char t;
    long long d;
    string s;
    cin >> n;
    vector<tuple<int, int, char, long long, string>> item(n);
    for (int i = 0; i < n; ++i) {
        cin >> v >> w >> t >> d >> s;
        item[i] = make_tuple(v, w, t, d, s);
    }

    sort(item.begin(), item.end());

    for (int i = 0; i < n; ++i) {
        tie(v, w, t, d, s) = item[i];
        printf("%d %d %c %lld %s\n", v, w, t, d, s.c_str());
    }
    return 0;
}
