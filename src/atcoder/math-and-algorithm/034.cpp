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
};

double getDistance(Point a, Point b) { return (a - b).abs(); }

int main() {
    int n;
    cin >> n;
    vector<Point> p(n);
    double ans = DBL_MAX;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, getDistance(p[i], p[j]));
        }
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}
