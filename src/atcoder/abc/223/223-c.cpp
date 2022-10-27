#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vl = vector<long long>;


int main(){
    int n;
    cin >> n;
    vd dist(n), speed(n), time(n);
    rep(i, n) cin >> dist[i] >> speed[i];

    double distt = 0.0, timet = 0.0;
    rep(i,n){
        time[i] = dist[i] / speed[i];
        distt += dist[i];
        timet += time[i];
    }
    double ta2 = timet / 2;

    double timex = 0.0, distx = 0.0, timey = 0.0, disty = 0.0;
    int x = 0, y = n - 1;

    while(timex + time[x] <= ta2){
        distx += dist[x];
        timex += time[x];
        ++x;
    }

    
    while(timey + time[y] < ta2){
        disty += dist[y];
        timey += time[y];
        --y;
    }

    double timep = abs(timex - timey);
    double distp = speed[y] * timep;

    if(timex > timey) disty += distp;
    else distx += distp;

    cout << fixed << setprecision(10);
    cout << distx + (distt - distx - disty) / 2;

}
