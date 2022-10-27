#include <bits/stdc++.h>
using namespace std;


int main(){
    int k;
    cin >> k;

    cout << (k<60 ? "21" : "22") << ':';
    k %= 60;
    if(k<10) cout << '0' << k;
    else cout << k;

    return 0;
}
