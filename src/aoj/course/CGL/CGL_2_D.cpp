#include <bits/stdc++.h>
using namespace std;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
const map<int, string> judge = {
    {1, "COUNTER_CLOCKWISE"}, {-1, "CLOCKWISE"}, {2, "ONLINE_BACK"},
    {-2, "ONLINE_FRONT"},     {0, "ON_SEGMENT"},
};

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
using Vector = Point;

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

using Line = Segment;

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

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2) { return intersect(s1.p1, s1.p2, s2.p1, s2.p2); }

double getDistanceLP(Line l, Point p) {
    Point s = l.p2 - l.p1;
    return abs(cross(l.p2 - l.p1, p - l.p1) / s.abs());
}

double getDistanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
        return (p - s.p1).abs();
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
        return (p - s.p2).abs();
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2) {
    if (intersect(s1, s2))
        return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

int main() {
    vector<Point> p(4);
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> p[j].x >> p[j].y;
        }
        Segment s1(p[0], p[1]), s2(p[2], p[3]);
        printf("%.10f\n", getDistance(s1, s2));
    }
    return 0;
}
