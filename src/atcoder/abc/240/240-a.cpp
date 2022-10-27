#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,d;
    cin >> a >> b;

    d = abs(a-b);
    if(d == 1 || d == 9 ) cout << "Yes";
    else cout << "No";
}
