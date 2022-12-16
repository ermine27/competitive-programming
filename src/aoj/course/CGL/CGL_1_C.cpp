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
    void print() { printf("%.10f %.10f\n", x, y); }
};

struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

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

int main() {
    Point p1, p2, pi;
    int q;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> q;
    Segment s(p1, p2);
    for (int i = 0; i < q; i++) {
        cin >> pi.x >> pi.y;
        int j = ccw(p1, p2, pi);

        // const map は [] で参照しようとするとコンパイルエラーになる
        // cout << judge[j] << endl;
        cout << judge.at(j) << endl;
    }

    return 0;
}
