#include <bits/stdc++.h>
using namespace std;


int main(){
    int H,W,R,C;
    cin >> H >> W >> R >> C;

    int ans = 0;

    if(R > 1) ++ans;
    if(R < H) ++ans;
    if(C > 1) ++ans;
    if(C < W) ++ans;

    cout << ans;

    return 0;    
}