#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,e,f,x, dt = 0, da = 0;
    cin >> a >> b >> c >> d >> e >> f >> x;

    int xt = 0;
    while(xt < x){
        ++xt;

        if(xt % (a+c) <= a) dt += b;
        if(xt % (d+f) <= d) da += e;
    }

    if(dt == da){
        cout << "Draw";
    }
    if(dt > da){
        cout << "Takahashi";
    }
    if(dt < da){
        cout << "Aoki";
    }
}
