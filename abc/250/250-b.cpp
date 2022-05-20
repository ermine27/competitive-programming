#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    rep(i, A*N){
        rep(j, B*N){
            int ax = i / A % 2;
            int bx = j / B % 2;
            if(ax == 1 && bx == 0 || ax == 0 && bx == 1){
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }

    return 0;
}
