/*
Geometory

[参考文献]

２．計算幾何のインフラ整備　　　シリーズ：「基礎的計算幾何ライブラリの作り方」
https://sen-comp.hatenablog.com/entry/2020/03/12/145742

幾何テンプレート(Geometry)
https://ei1333.github.io/luzhiled/snippets/geometry/template.html

Vec2 クラスを作る（モダンな C++ クラスデザインのためのチュートリアル）
https://qiita.com/Reputeless/items/96226cfe1282a014b147

幾何ライブラリについてのメモ
https://bakamono1357.hatenablog.com/entry/2020/04/29/025320

ベクトルの利用　complexの導入
http://www.deqnotes.net/acmicpc/2d_geometry/using_vectors#complex_introduction
ソースコード
http://www.deqnotes.net/acmicpc/2d_geometry/source_codes

https://github.com/siro53/compro_library/blob/main/geometry/geometry.hpp

https://github.com/drken1215/algorithm/blob/master/Geometry/basic_elements.cpp

http://www.deqnotes.net/acmicpc/2d_geometry/source_codes

*/

#include "header.cpp"

// constexpr double EPS = DBL_EPSILON;
constexpr double EPS = 1e-10;

// 数の比較
#define equals(a, b) (fabs(a - b) < EPS)

int sgn(double a) { return (a < -EPS) ? -1 : (a > EPS) ? 1 : 0; }

// 点
struct Point {
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) { return Point(x - p.x, y - p.y); }
    Point operator*(const double &k) { return Point(x * k, y * k); }
    Point operator/(const double &k) { return Point(x / k, y / k); }

    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
    // bool operator==(const Vector &p) const {
    //     return fabs(x - p.x) < DBL_EPSILON && fabs(y - p.y) < DBL_EPSILON;
    // }

    // 出力
    void print() { printf("%.10f %.10f\n", x, y); }
};

// ノルム（ユークリッド・ノルム）
double norm(const Point &p) { return p.x * p.x + p.y * p.y; }
// 大きさ
double abs(const Point &p) { return sqrt(norm(p)); }

// ベクトル
using Vector = Point;

// 線分
struct Segment {
    Point p1, p2;
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

// 直線
using Line = Segment;

// 内積
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
// 外積
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

// 射影
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

// 直交判定
bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) { return isOrthogonal(a1 - a2, b1 - b2); }
bool isOrthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

// 平行判定
bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool isParallel(Point a1, Point a2, Point b1, Point b2) { return isParallel(a1 - a2, b1 - b2); }
bool isParallel(Segment s1, Segment s2) { return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

// 反射
Point reflection(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }

constexpr int CCW_COUNTER_CLOCKWISE = 1;  // 反時計回り
constexpr int CCW_CLOCKWISE = -1;         // 時計回り
constexpr int CCW_ONLINE_BACK = 2;        // p2-p1-p0 の順で直線上
constexpr int CCW_ONLINE_FRONT = -2;      // p0-p1-p2 の順で直線上
constexpr int CCW_ON_SEGMENT = 0;         // p0-p2-p1 の順で直線上

// 回転
int ccw(Point p0, Point p1, Point p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (cross(a, b) > EPS)
        return CCW_COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS)
        return CCW_CLOCKWISE;
    if (dot(a, b) < -EPS)
        return CCW_ONLINE_BACK;
    if (norm(a) < norm(b))
        return CCW_ONLINE_FRONT;
    return CCW_ON_SEGMENT;
}

// 直線の交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2) { return intersect(s1.p1, s1.p2, s2.p1, s2.p2); }

// 交点の座標
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

// 2点間の距離
double getDistance(Point a, Point b) { return abs(a - b); }

// 点と直線の距離
double getDistanceLP(Line l, Point p) {
    Point s = l.p2 - l.p1;
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(s));
}

// 点と線分の距離
double getDistanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
        return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
        return abs(p - s.p2);
    return getDistanceLP(s, p);
}

// 線分と線分の距離
double getDistance(Segment s1, Segment s2) {
    if (intersect(s1, s2))
        return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

// ===========================================================================

// 多角形
using Polygon = vector<Point>;

// 多角形の面積を求める
//  S = 1/2 * |Σ_{i=1}^n(p_{i_x} * p_{{i+1}_y} - p_{i+1_x} * p_{i_y})|
double area(Polygon &p) {
    int n = p.size();
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        res += cross(p[i], p[(i + 1) % n]);
    }
    return res * 0.5;
}

// 凸性判定
bool isConvex(Polygon &p) {
    bool res = true;

    int n = p.size();
    for (int i = 0; i < n; i++) {
        if (ccw(p[i], p[(i + 1) % n], p[(i + 2) % n]) == -1)
            res = false;
    }
    return res;
}

// 点の包含判定（2:多角形に含まれる、1:多角形の辺上にある、0:多角形の外側にある）
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

// 凸包を求める
// andrew's monotone chain convex hull algorithm
Polygon convexHull(Polygon s) {
    Polygon u, l;
    int size = s.size();
    if (size < 3)
        return s;
    sort(s.begin(), s.end());

    // x が小さいものから２つ u に追加
    u.push_back(s[0]);
    u.push_back(s[1]);
    // x が大きいものから２つ l に追加
    l.push_back(s[size - 1]);
    l.push_back(s[size - 2]);

    // 凸包の上部を生成
    for (int i = 2; i < size; i++) {
        for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) > CCW_CLOCKWISE; n--) {
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    // 凸包の下部を生成
    for (int i = size - 3; i >= 0; i--) {
        for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) > CCW_CLOCKWISE; n--) {
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    // 時計回りになるように凸包の点の列を生成
    reverse(l.begin(), l.end());
    for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

    return l;
}

// 直径（最遠頂点対間距離）とその時の２点を求める
// キャリパー法：図形を回転させながら探索する
pair<double, pair<int, int>> convexDiameter(Polygon &p) {
    int n = p.size();
    int is = 0, js = 0;

    // max(y)とmin(y)のペアを探索開始位置にする
    for (int i = 0; i < n; i++) {
        if (p[i].y > p[is].y)
            is = i;
        if (p[i].y < p[js].y)
            js = i;
    }

    double res = 0.0;
    int i, j, maxi, maxj;
    i = maxi = is, j = maxj = js;
    do {
        int ii = (i + 1) % n;
        int jj = (j + 1) % n;

        // iとjのどちらの点を動かすかを判断して移動する
        if (cross(p[ii] - p[i], p[jj] - p[j]) < 0)
            i = ii;
        else
            j = jj;

        double t = abs(p[i] - p[j]);
        if (t > res) {
            res = t;
            maxi = i;
            maxj = j;
        }

    } while (i != is || j != js);

    return make_pair(res, minmax(maxi, maxj));
}

// 凸多角形の切断
// Line(p1,p2) で切った左側の図形を生成する
Polygon convexCut(Polygon p, Line l) {
    Polygon q;
    for (int i = 0; i < (int)p.size(); ++i) {
        Point a = p[i], b = p[(i + 1) % p.size()];
        if (ccw(l.p1, l.p2, a) != CCW_CLOCKWISE)
            q.push_back(a);
        if (ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) == -1)
            q.push_back(getCrossPoint(Line(a, b), l));
    }
    return q;
}

// ===========================================================================

// 円
struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

// 円の交差判定（共通接線の数）
int circleIntersect(Circle c1, Circle c2) {
    double d = abs(c1.c - c2.c);

    if (d < abs(c1.r - c2.r))
        return 0;
    if (d == abs(c1.r - c2.r))
        return 1;
    if (d > c1.r + c2.r)
        return 4;
    if (d == c1.r + c2.r)
        return 3;
    return 2;
}

// 円と直線の交点
// 注）
// ・交点がある前提になっているので、円と直線が接しない場合は-nanを返す。
// ・交点が1つの場合は同じ座標を2回返す。
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}

double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

// ２つの円の交点
// 注）
// ・交点がある前提になっているので、円と直線が接しない場合は-nanを返す。
// ・交点が1つの場合は同じ座標を2回返す。
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

// ===========================================================================
// その他

// 複数の点の集合の最近点対（最も近い2点の距離）を求める
// 分割統治法を使って高速化する
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
                res = min(res, abs(a[i] - b[j]));
            }
            b.push_back(a[i]);
        }
        return res;
    };

    return dfs(dfs, 0, a.size());
}

int main() {
    //     Vector a(1.2,1.0),b(2.4,-0.3),c(4.0,2.0),d(-5.3,-2.6);
    //     c = a-b;
    //     d = a*2.0;
    // dbg(a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y);

    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    Segment s = {b, c};
    double ans;

    ans = getDistance(a, b);
    printf("%.10f\n", ans);

    ans = getDistanceSP(s, a);
    printf("%.10f\n", ans);

    // cout << setprecision(10) << ans << endl;
    return 0;
}
