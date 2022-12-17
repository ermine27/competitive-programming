#include <bits/stdc++.h>
using namespace std;

const double EPS = DBL_EPSILON;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point &p) { return Point(x - p.x, y - p.y); }
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

int contains(Polygon g, Point p) {
    int n = g.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = g[i] - p;
        Point b = g[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS && dot(a, b) < EPS)
            return 1;
        if (a.y > b.y)
            swap(a, b);
        if (a.y < EPS && EPS < b.y && cross(a, b) > EPS)
            x = !x;
    }
    return (x ? 2 : 0);
}

int main() {
    int q, n;
    cin >> q;
    Polygon g(q);
    for (int i = 0; i < q; i++) {
        Point p;
        cin >> p.x >> p.y;
        g[i] = p;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        cout << contains(g, p) << endl;
    }

    return 0;
}
