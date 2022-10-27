#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        vector<int> s(n);
        
        for(int i = 0; i < n; ++i) cin >> s[i];

        double ave = 0.0;
        for(int i = 0; i < n; ++i) ave += s[i];
        ave /= n;

        double alpha = 0.0;
        for(int i = 0; i < n; ++i) alpha += pow(s[i] - ave, 2);
        alpha /= n;
        alpha = sqrt(alpha);
        cout << fixed << alpha << endl;
    }
}
