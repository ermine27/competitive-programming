#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;

    int head = 0;
    rep(i,q){
        int c,x;
        cin >> c >> x;
        if(c == 1){
            head = (head + n - x) % n;
        } else {
            cout << s[(head+x-1) % n] << endl;
        }
    }

    return 0;
}
