#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
int arr[500000];
int main()
{
    io;
    int N,tower;
    cin>>N;
    stack<pair<int,int>> st,tst;
    for(int i=0;i<N;i++){
        cin>>tower;
        st.emplace(tower,i);
    }
    while(!st.empty()){
        int temp=st.size();
        auto top=st.top();
        st.pop();
        while(!st.empty()&&top.first>st.top().first){
            tst.push(st.top());
            st.pop();
            while(!st.empty()&&!tst.empty()&&st.top().first>tst.top().first){
                arr[tst.top().second]=st.size();
                tst.pop();
            }
        }
        arr[top.second]=st.size();
    }

    for(int i=0;i<N;i++) cout<<arr[i]<<' ';
    return 0;
}