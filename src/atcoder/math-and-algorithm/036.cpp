#include <bits/stdc++.h>
using namespace std;

// 長針と短針に挟まれた角度を求める
double angleBetweenHands(int h, int m) {
    double longhand, shorthand;
    // 長針 1分で6度動く
    // → 360度/60分=6度/分
    longhand = M_PI / 180 * m * 6;
    // 短針 1時間で30度、1分で0.5度動く
    // → 360度/12時間=30度/時間=0.5度/分
    shorthand = M_PI / 180 * (h * 30 + m * 0.5);
    return max(longhand, shorthand) - min(longhand, shorthand);
}

int main() {
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    printf("%.10f\n", sqrt(a * a + b * b - 2 * a * b * cos(angleBetweenHands(h, m))));
    return 0;
}
