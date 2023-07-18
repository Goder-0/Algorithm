#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;
    stack<int> st;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        if(s=="push"){
            int n;
            cin>>n;
            st.push(n);
        }else if(s=="top"){
            if(!st.empty()){
                cout<<st.top()<<'\n';
            }else cout<<"-1\n";
        }else if(s=="size"){
            cout<<st.size()<<'\n';
        }else if(s=="empty"){
            cout<<st.empty()<<'\n';
        }else if(s=="pop"){
            if(!st.empty()){
                cout<<st.top()<<'\n';
                st.pop();
            }else cout<<"-1\n";
        }
    }
    return 0;
}