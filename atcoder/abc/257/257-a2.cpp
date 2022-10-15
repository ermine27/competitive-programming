#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)


int main(){
    int n, x;
    cin >> n >> x;

    int a = (x-1) / n;
    char c = 'A' + a;
    cout << c << endl;

    return 0;
}
