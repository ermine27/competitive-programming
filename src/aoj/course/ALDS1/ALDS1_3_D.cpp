#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    stack<tuple<int,int,int>> st2;
    int l2,i2,s2;
    char c;
    int i = 0;

    while(cin >> c){
        if(c == '\\'){
            st.push(i);            
        } else if(c == '/'){
            if(st.empty() == false){
                int l = st.top();
                st.pop();
                int s = i - l;

                while(st2.empty() == false){
                    tie(l2,i2,s2) = st2.top();
                    if(l < l2 && i2 < i){
                        st2.pop();
                        s += s2;
                    } else {
                        break;
                    }
                }
                st2.push(make_tuple(l,i,s));
            }

        }
        ++i;
    }

    vector<int> ans;
    int sum = 0;
    while(st2.empty() == false){
        tie(l2,i2,s2) = st2.top();
        st2.pop();
        ans.push_back(s2);
        sum += s2;
    }

    cout << sum << endl;
    cout << ans.size();
    for(int i = ans.size() - 1; i >= 0; --i){
        cout << ' ' << ans[i];
    }
    cout << endl;
    
    return 0;
}
