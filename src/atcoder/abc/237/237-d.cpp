#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;


int main(){
    int n;
    string s;
    cin >> n >> s;

    vi front(n+1,-1), back(n+1,-1);

    reps(i,1,n+1){
        if(s[i-1] == 'L'){
            front[i] = front[i-1];
            back[i] = i-1;
            front[i-1] = i;
            if(front[i] != -1){
                back[front[i]] = i;
            }
        } else {
            front[i] = i-1;
            back[i] = back[i-1];
            back[i-1] = i;
            if(back[i] != -1){
                front[back[i]] = i;
            }
        }
    }

    int x = 0;
    while(front[x] != -1) ++x;

    cout << x;
    while(back[x] != -1){
        x = back[x];
        cout << ' ' << x;
    }

    return 0;
}
