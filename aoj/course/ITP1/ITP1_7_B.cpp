#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n, x;
        cin >> n >> x;

        if(n == 0 && x == 0) break;

        int ans = 0;
        for(int i = 1; i <= n - 2; ++i){
            for(int j = i + 1; j <= n - 1; ++j){
                int a = x - (i + j);
                if(a > j && a <= n) ++ans;
            }
        }

        cout << ans << endl;
    }
}

