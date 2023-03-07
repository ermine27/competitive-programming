#include <bits/stdc++.h>
using namespace std;

// double型だとWAするテストケースが出てくるのでlong double型にする
// constexpr long double EPS = 1e-10;
constexpr long double EPS = DBL_EPSILON;

struct Point {
    long double x, y;
    Point(long double x = 0.0, long double y = 0.0) : x(x), y(y) {}
    Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(const long double &k) { return Point(x * k, y * k); }
    Point operator/(const long double &k) { return Point(x / k, y / k); }
};

using Vector = Point;
using Polygon = vector<Point>;

long double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
long double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

int contains(Polygon s, Point p) {
    int n = s.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = s[i] - p;
        Point b = s[(i + 1) % n] - p;
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
    int n;
    cin >> n;
    Polygon p(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }
    int a, b;
    cin >> a >> b;
    cout << (contains(p, Point(a, b)) ? "INSIDE" : "OUTSIDE") << endl;
    return 0;
}
