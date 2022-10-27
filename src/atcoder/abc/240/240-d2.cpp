// 改善版：番兵を立てることで初期のスタックが空の場合の分岐をなくせる

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using vi = vector<int>;

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    stack<int> stk1, stk2;
    stk1.push(-1);
    stk2.push(0);
    int top, cnt, total = 0;

    rep(i,n){
        ++total;

        top = stk1.top();
        cnt = stk2.top();

        if(a[i] == top){
            stk1.pop();
            stk2.pop();
            cnt++;

            if(cnt == top){
                total -= top;
            } else {
                stk1.push(top);
                stk2.push(cnt);
            }
        } else {
            stk1.push(a[i]);
            stk2.push(1);
        }

        cout << total << endl;
    }

    return 0;
}
