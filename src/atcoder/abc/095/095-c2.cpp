#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1e9;
    int cmax = max(x,y) * 2;

    for(int i = 0; i <=cmax; ++i){
        int na = max(0,(x-i/2));
        int nb = max(0,(y-i/2));
        ans = min(ans, (na * a + nb * b + c * i) );
    }

    cout << ans;
}
