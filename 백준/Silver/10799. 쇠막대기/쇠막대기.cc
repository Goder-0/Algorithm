#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{
    io;
    string s;
    stack<char> st;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='('){
            st.push(c);
        }
        else{
            if(s[i-1]=='('){
                st.pop();
                ans+=st.size();
            }else{
                st.pop();
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
