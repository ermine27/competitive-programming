/*
解法１：周期性を見つける
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n), step;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = t - 1;
    }

    map<int, int> m;
    int cnt = 0;
    int cur = 0;
    while (m.count(cur) == 0 && cnt < n) {
        m[cur] = cnt;
        step.push_back(cur);
        cur = a[cur];
        cnt++;
    }

    int left = m[cur];
    int right = cnt;

    int ans;
    if (k < left) {
        ans = step[k];
    } else {
        ans = step[left + (k - left) % (right - left)];
    }
    cout << ans + 1 << endl;
    return 0;
}
