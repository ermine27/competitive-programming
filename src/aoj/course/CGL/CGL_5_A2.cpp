#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }
    void print() { cout << x << ' ' << y << endl; }
};

// 最近点対：再帰処理の部分だけをラムダ関数で書き換え
double closetPair(vector<Point> &a) {
    sort(a.begin(), a.end());
    auto compare_y = [&](const Point &a, const Point &b) { return a.y < b.y; };

    auto dfs = [&](auto self, int l, int r) -> double {
        if (r - l <= 1)
            return DBL_MAX;
        int m = (l + r) / 2;
        double x = a[m].x;

        double res = min(self(self, l, m), self(self, m, r));
        inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r, compare_y);

        vector<Point> b;
        for (int i = l; i < r; i++) {
            if (fabs(a[i].x - x) >= res)
                continue;
            for (int j = b.size() - 1; j >= 0; j--) {
                if (abs((a[i] - b[j]).y) >= res)
                    break;
                res = min(res, (a[i] - b[j]).abs());
            }
            b.push_back(a[i]);
        }
        return res;
    };

    return dfs(dfs, 0, a.size());
}

int main() {
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    printf("%.10f\n", closetPair(a));
    return 0;
}
