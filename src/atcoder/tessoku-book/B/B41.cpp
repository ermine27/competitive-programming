#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    vector<pair<int,int>> ans;

    while(x > 1 || y > 1){
        ans.push_back({x, y});
        int d = abs(x - y);
        if(x > y){
            x = d;
        } else {
            y = d;
        }
    }

    int n = ans.size();
    cout << n << endl;
    for(int i = n-1; i >= 0; i--){
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}
