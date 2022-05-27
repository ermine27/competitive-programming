#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    double x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    // 正多角形の中心座標（＝ 内接円の中心座標）
    double cx = (x0 + x1) / 2.0;
    double cy = (y0 + y1) / 2.0;

    // 向かい合う頂点の距離（＝ 内接円の直径）
    double r = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
    // 内接円の半径（＝中心から正多面体の各頂点までの距離）
    r /= 2.0;

    // 中心からみたp0の方位
    double arg1 = atan2(y0-cy, x0-cx);
    // 回転させる確度（角 P0 C P1）
    double arg2 = (360.0 / n) * M_PI / 180;

    // 中心からp0+p1度、回転させるとp1の位置が求まる
    double ax = cx + r * cos(arg1 + arg2);
    double ay = cy + r * sin(arg1 + arg2);

    cout << fixed << setprecision(10);
    cout << ax << ' ' << ay;
}
