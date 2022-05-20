/*
ランレングス符号化・ランレングス圧縮 (RLE)

キューを使う場合、whileの中で常に一度popして余りをpushするとキューの中身の順番が変わるのでダメ
Dequeにして、push_front() を使えばこの方法でもできる

*/
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;


int main(){
    int Q;
    cin >> Q;
    int qi, x, c;

    queue<int> que1, que2;
    rep(i,Q){
        cin >> qi;
        if(qi == 1){

            cin >> x >> c;
            que1.push(x);
            que2.push(c);

        } else {

            cin >> c;
            ll ans = 0;
            ll cnt = 0;

            while(c > 0){
                ll q1 = que1.front();
                ll q2 = que2.front();

                if(q2 > c){
                    ans += q1 * c;
                    que2.front() -= c;
                    c = 0;
                } else {
                    ans += q1 * q2;
                    c -= q2;
                    que1.pop();
                    que2.pop();
                }

            }

            cout << ans << endl;
        }
    }

    return 0;
}
