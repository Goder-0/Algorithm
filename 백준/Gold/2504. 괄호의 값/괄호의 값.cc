#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{
    io;
    string s;
    cin>>s;
    stack<int> st;
    int ans=0;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='('){
            st.push(-1);
        }else if(c=='['){
            st.push(-2);
        }else if(c==')'){
            if(s[i-1]=='('){
                st.pop();
                st.push(2);
            }else{
                int temp=0;
                while(!st.empty()&&st.top()>0){
                    temp+=st.top();
                    st.pop();
                }
                if(st.empty()||st.top()!=-1){//강제 종료
                    cout<<0;
                    return 0;
                }
                st.pop();
                st.push(temp*2);
            }
        }else if(c==']'){
            if(s[i-1]=='['){
                st.pop();
                st.push(3);
            }else{
                int temp=0;
                while(!st.empty()&&st.top()>0){
                    temp+=st.top();
                    st.pop();
                }
                if(st.empty()||st.top()!=-2){//강제 종료
                    cout<<0;
                    return 0;
                }
                st.pop();
                st.push(temp*3);
            }
        }
    }
    while(!st.empty()&&st.top()>0){
        ans+=st.top();
        st.pop();
    }
    if(!st.empty()) cout<<0;
    else cout<<ans;
    return 0;
}
