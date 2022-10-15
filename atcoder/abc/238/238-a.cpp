#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;

    if(pow(2,n) > pow(n,2)) cout << "Yes";
    else cout << "No";
}
