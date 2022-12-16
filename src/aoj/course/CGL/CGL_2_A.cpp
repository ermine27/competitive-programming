#include <bits/stdc++.h>
using namespace std;

#define equals(a, b) (fabs(a - b) < DBL_EPSILON)

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
};
using Vector = Point;

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) { return isOrthogonal(a1 - a2, b1 - b2); }

bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool isParallel(Point a1, Point a2, Point b1, Point b2) { return isParallel(a1 - a2, b1 - b2); }

int main() {
    vector<Point> p(4);
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) cin >> p[j].x >> p[j].y;
        if (isOrthogonal(p[0], p[1], p[2], p[3]))
            cout << 1;
        else if (isParallel(p[0], p[1], p[2], p[3]))
            cout << 2;
        else
            cout << 0;
        cout << endl;
    }

    return 0;
}
