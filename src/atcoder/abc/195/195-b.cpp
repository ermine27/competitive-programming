#include <bits/stdc++.h>
using namespace std;


int main(){
    double a,b,w;
    int min,max;
    cin >> a >> b >> w;
    w *= 1000;

    min = ceil(w / b);
    max = floor(w / a);

    if(min > max) cout << "UNSATISFIABLE";
    else cout << min << ' ' << max;
}
