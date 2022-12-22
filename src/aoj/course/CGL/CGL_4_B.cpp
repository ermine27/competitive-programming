#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }
};
using Polygon = vector<Point>;

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

// 直径（最遠頂点対間距離）とその時の２点を求める
// キャリパー法：図形を回転させながら探索する
pair<double, pair<int, int>> convexDiameter(Polygon &p) {
    int n = p.size();
    int is = 0, js = 0;

    // max(y)とmin(y)のペアを探索開始位置にする
    for (int i = 0; i < n; i++) {
        if (p[i].y > p[is].y)
            is = i;
        if (p[i].y < p[js].y)
            js = i;
    }

    double res = 0.0;
    int i, j, maxi, maxj;
    i = maxi = is, j = maxj = js;
    do {
        int ii = (i + 1) % n;
        int jj = (j + 1) % n;

        // iとjのどちらの点を動かすかを判断して移動する
        if (cross(p[ii] - p[i], p[jj] - p[j]) < 0)
            i = ii;
        else
            j = jj;

        double t = (p[i] - p[j]).abs();
        if (t > res) {
            res = t;
            maxi = i;
            maxj = j;
        }

    } while (i != is || j != js);

    return make_pair(res, minmax(maxi, maxj));
}

int main() {
    int n;
    cin >> n;
    Polygon s(n);
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        s[i] = p;
    }

    double ans;
    pair<int, int> ap;
    tie(ans, ap) = convexDiameter(s);
    printf("%.7f\n", ans);
    return 0;
}
