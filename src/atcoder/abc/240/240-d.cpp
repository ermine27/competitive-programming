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
    int top, cnt, total = 0;

    rep(i,n){
        ++total;
        if(stk2.empty()){
            top = -1;
            cnt = 0;
        } else {
            top = stk1.top();
            stk1.pop();
            cnt = stk2.top();
            stk2.pop();
        }

        if(a[i] == top){
            cnt++;
            if(cnt == top){
                total -= top;
            } else {
                stk1.push(top);
                stk2.push(cnt);
            }
        } else {
            if(stk2.empty() == true || top != -1){
                stk1.push(top);
                stk2.push(cnt);
            }
            stk1.push(a[i]);
            stk2.push(1);
        }

        cout << total << endl;
    }

    return 0;
}
