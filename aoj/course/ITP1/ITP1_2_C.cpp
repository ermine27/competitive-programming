#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    if(a < b){
        if(b < c){
            cout << a << ' ' << b << ' ' << c << endl;
        } else { // a < b, c < b
            if(a < c) cout << a << ' ' << c << ' ' << b << endl;
            else cout << c << ' ' << a << ' ' << b << endl;
        }
    }else{  // b < a
        if(a < c){ // b < ? < ?
            cout << b << ' ' << a << ' ' << c << endl;
        } else { // b < a,  c < a
            if(b < c) cout << b << ' ' << c << ' ' << a << endl;
            else cout << c << ' ' << b << ' ' << a << endl;

        }
    }
}
