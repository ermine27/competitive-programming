#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;

const double rad60 = M_PI / 180 * 60;

struct point{
    double x;
    double y;
};

void koch(int x, point a, point b){
    if(x == 0) return;

    point s,t,u;

    s.x = (a.x * 2 + b.x) / 3;
    s.y = (a.y * 2 + b.y) / 3;
    t.x = (a.x + b.x * 2) / 3;
    t.y = (a.y + b.y * 2) / 3;

    u.x = (t.x - s.x) * cos(rad60) - (t.y - s.y) * sin(rad60) + s.x;
    u.y = (t.x - s.x) * sin(rad60) + (t.y - s.y) * cos(rad60) + s.y;

    koch(x-1, a, s);
    cout << s.x << ' ' << s.y << endl;
    koch(x-1, s, u);
    cout << u.x << ' ' << u.y << endl;
    koch(x-1, u, t);
    cout << t.x << ' ' << t.y << endl;
    koch(x-1, t, b);
}

int main(){
    cout << fixed << setprecision(10);

    int N;
    cin >> N;
    point p1 = {0,0}, p2 = {100,0};

    cout << p1.x << ' ' << p1.y << endl;
    koch(N, p1, p2);
    cout << p2.x << ' ' << p2.y << endl;

    return 0;    
}

