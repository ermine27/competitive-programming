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

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

Point project(Segment s, Point p) {
    Point base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

int main() {
    Point p1, p2, pi;
    int q;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> q;
    Segment s(p1, p2);
    for (int i = 0; i < q; i++) {
        cin >> pi.x >> pi.y;
        project(s, pi).print();
    }

    return 0;
}
