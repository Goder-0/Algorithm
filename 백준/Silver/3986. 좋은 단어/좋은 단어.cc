#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,res=0;
    cin>>N;
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        stack<char> st;
        for(char c : s){
            if(!st.empty()&&st.top()==c) st.pop();
            else st.push(c);
        }
        if(st.empty()) res++;
    }

    cout<<res;
    return 0;
}