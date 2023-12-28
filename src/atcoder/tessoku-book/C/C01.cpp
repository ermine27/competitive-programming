#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // 小数を含む場合ば整数型でキャストしないと大きい数値の時に指数表示されるので注意
    cout << (int)(n * 1.1) << endl;
    // cout << n + (n/10) << endl;
    return 0;
}
