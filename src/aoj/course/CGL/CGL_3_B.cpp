#include <bits/stdc++.h>
using namespace std;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    double norm() { return x * x + y * y; }
};
using Polygon = vector<Point>;

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

int ccw(Point p0, Point p1, Point p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (cross(a, b) > DBL_EPSILON)
        return COUNTER_CLOCKWISE;
    if (cross(a, b) < -DBL_EPSILON)
        return CLOCKWISE;
    if (dot(a, b) < -DBL_EPSILON)
        return ONLINE_BACK;
    if (a.norm() < b.norm())
        return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool isConvex(Polygon p) {
    bool res = true;

    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (ccw(p[i], p[(i + 1) % n], p[(i + 2) % n]) == -1)
            res = false;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    Polygon polygon(n);
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        polygon[i] = p;
    }
    cout << (isConvex(polygon) ? "1" : "0") << endl;
    return 0;
}
