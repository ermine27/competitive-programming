#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};
using Polygon = vector<Point>;

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

double polygonArea(Polygon p) {
    int n = p.size();
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += cross(p[i], p[i + 1]);
    }
    res += cross(p[n - 1], p[0]);
    return res * 0.5;
}

int main() {
    int n;
    cin >> n;
    Polygon polygon;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        polygon.push_back(p);
    }
    printf("%.1f\n", polygonArea(polygon));
    return 0;
}
