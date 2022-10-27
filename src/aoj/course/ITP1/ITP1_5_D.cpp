#include <bits/stdc++.h>
using namespace std;

int call(int n){
    int x, i = 1;

    do{
        int x = i;

        if(x % 3 == 0){
            cout << " " << i;
        } else {
            do{
                if(x % 10 == 3){
                    cout << " " << i;
                    break;
                }
                x /= 10;
            }while(x);
        }

        ++i;
    }while(i <= n);
}


int main(){
    int n;
    cin >> n;

    call(n);
}
