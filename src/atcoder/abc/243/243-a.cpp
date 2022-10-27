#include <bits/stdc++.h>
using namespace std;

int main(){
    int v,a,b,c;
    cin >> v >> a >> b >> c;
    int dd = a + b + c;
    v %= dd;

    char ans;
    v -= a;
    if(v<0) ans = 'F';
    else {
        v -= b;
        if(v<0) ans = 'M';
        else ans = 'T';
    }
    
    cout << ans;

}