#include <bits/stdc++.h>
using namespace std;

int main(){
    int time,h,m,s;
    cin >> time;
    h = time / 3600;
    m = (time % 3600) / 60;
    s = time % 60;
    printf("%d:%d:%d\n", h,m,s);
}
