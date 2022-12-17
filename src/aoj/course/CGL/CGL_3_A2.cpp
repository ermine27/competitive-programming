#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

struct Polygon {
    vector<Point> vertex;

    double area() {
        int n = vertex.size();
        double res = 0.0;
        for (int i = 0; i < n; i++) {
            res += cross(vertex[i], vertex[i + 1]);
        }
        res += cross(vertex[n - 1], vertex[0]);
        return res * 0.5;
    }
};

int main() {
    int n;
    cin >> n;
    Polygon polygon;
    for (int i = 0; i < n; i++) {
        Point p;
        cin >> p.x >> p.y;
        polygon.vertex.push_back(p);
    }
    printf("%.1f\n", polygon.area());
    return 0;
}
