#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
using ll = long long;


int main(){
    ll n;
    cin >> n;
    string s = "";

    while(n > 0){
        if(n % 2 == 0){
            n /= 2;
            s += 'B';
        }else{
            --n;
            s += 'A';
        }
    }
    
    reverse(all(s));
    cout << s;
}