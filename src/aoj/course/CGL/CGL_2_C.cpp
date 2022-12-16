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
    void print() { printf("%.10f %.10f\n", x, y); }
};
using Vector = Point;

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}
Point getCrossPoint(Point p1, Point p2, Point p3, Point p4) {
    return getCrossPoint(Segment(p1, p2), Segment(p3, p4));
}

int main() {
    vector<Point> p(4);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> p[j].x >> p[j].y;
        }
        getCrossPoint(p[0], p[1], p[2], p[3]).print();
    }
    return 0;
}
