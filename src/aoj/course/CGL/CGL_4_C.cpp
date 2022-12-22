#include <bits/stdc++.h>
using namespace std;

const double EPS = DBL_EPSILON;

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

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
int ccw(Point p0, Point p1, Point p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (cross(a, b) > EPS)
        return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS)
        return CLOCKWISE;
    if (dot(a, b) < -EPS)
        return ONLINE_BACK;
    if (a.norm() < b.norm())
        return ONLINE_FRONT;
    return ON_SEGMENT;
}

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};
using Line = Segment;

Point getCrossPoint(Segment s1, Segment s2) {
    Point base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

Polygon convexCut(Polygon p, Line l) {
    Polygon q;
    for (int i = 0; i < (int)p.size(); ++i) {
        Point a = p[i], b = p[(i + 1) % p.size()];
        if (ccw(l.p1, l.p2, a) != CLOCKWISE)
            q.push_back(a);
        if (ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) == -1)
            q.push_back(getCrossPoint(Line(a, b), l));
    }
    return q;
}

double area(Polygon p) {
    int n = p.size();
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += cross(p[i], p[(i + 1) % n]);
    }
    return res * 0.5;
}

int main() {
    int n, q;
    cin >> n;
    Polygon s(n);
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        s[i] = p;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        printf("%.7f\n", area(convexCut(s, Line(p1, p2))));
    }
    return 0;
}
