#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= days[i - 1]; j++) {
            if (i == j / 10 + j % 10) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
