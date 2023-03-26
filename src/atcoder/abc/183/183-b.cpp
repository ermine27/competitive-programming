/*
y軸との接点をP(X,0)として、直接PSとPGの傾きを求める。
  a1 = Sy/(Sx-X)
  a2 = Gy/(Gx-X)
入射角と反射角が等しいということはa1 = -a2である。
式変形をしてXを求める。
  a1 + a2 = 0
  Sy/(Sx-X) + Gy/(Gx-X) = 0
  SyGx - SyX + SxGy - GyX = 0
  SyGx + SxGy = SyX + GyX
  X = (SyGx + SxGy) / (Sy + Gy)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    cout << setprecision(10) << (sy * gx + sx * gy) / (sy + gy) << endl;
    return 0;
}
