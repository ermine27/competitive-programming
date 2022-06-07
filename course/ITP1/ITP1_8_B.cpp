#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        string x;
        cin >> x;

        if(x == "0") return 0;

        int s = 0;
        for(int i = 0; i < x.length(); ++i) s += x[i] - '0';
        cout << s << endl;
    }
}

