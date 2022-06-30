/*
二分ヒープ

節点iについて、
　iの親　　　　floor(i)
　iの左側の子　2*i
　iの右側の子　2*i+1

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using vi = vector<int>;


int main(){
    int h;
    cin >> h;
    vi a(h+1);
    repf(i,h) cin >> a[i];

    repf(i,h){
        cout << "node " << i << ": key = " << a[i] << ", ";
        if(i != 1){
            cout << "parent key = " << a[floor(i/2)] << ", ";
        }
        if(i*2 <= h){
            cout << "left key = " << a[i*2] << ", ";
        }
        if(i*2+1 <= h){
            cout << "right key = " << a[i*2+1] << ", ";
        }
        cout << endl;
    }

    return 0;
}
