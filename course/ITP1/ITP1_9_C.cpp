#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, pttaro = 0, pthanako = 0;
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        string cdtaro,cdhanako;
        cin >> cdtaro >> cdhanako;
        if(cdtaro == cdhanako){
            pttaro++;
            pthanako++;
        }
        if(cdtaro > cdhanako){
            pttaro += 3;
        }
        if(cdtaro < cdhanako){
            pthanako += 3;
        }
    }

    cout << pttaro << ' ' << pthanako << endl;
}
