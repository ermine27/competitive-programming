#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    double norm() { return x * x + y * y; }
    // Pointに対してsort関数を使う際に必要
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
    void print() { cout << x << ' ' << y << endl; }
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

Polygon convexHull(Polygon s) {
    Polygon u, l;
    int size = s.size();
    if (size < 3)
        return s;
    sort(s.begin(), s.end());

    u.push_back(s[0]);
    u.push_back(s[1]);
    l.push_back(s[size - 1]);
    l.push_back(s[size - 2]);

    for (int i = 2; i < size; i++) {
        for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) > CLOCKWISE; n--) {
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    for (int i = size - 3; i >= 0; i--) {
        for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) > CLOCKWISE; n--) {
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    reverse(l.begin(), l.end());
    for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

    return l;
}

int findFirstPoint(Polygon &p) {
    int res = 0;
    for (int i = 1; i < (int)p.size(); i++) {
        if (p[i].y != p[res].y ? p[i].y < p[res].y : p[i].x < p[res].x)
            res = i;
    }
    return res;
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

    Polygon a = convexHull(s);
    int f = findFirstPoint(a);

    cout << a.size() << endl;
    for (int i = 0; i < (int)a.size(); i++) {
        a[(f + i) % a.size()].print();
    }

    return 0;
}
