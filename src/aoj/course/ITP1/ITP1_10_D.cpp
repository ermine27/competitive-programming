#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    for(int p = 1; p <= 3; ++p){
        double d = 0.0;
        for(int i = 0; i < n; ++i){
            d += pow(abs(a[i] - b[i]),p);
        }
        d =  pow(d, 1/(0.0+p));
        cout << d << endl;
    }

    int dm = 0;
    for(int i = 0; i < n; ++i){
        dm = max(dm, abs(a[i] - b[i]));
    }
    cout << dm << endl;
}

