#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <memory.h>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

pair<int,int> visited[10001];
stack<char> st;
queue<int> op;
queue<int> q;

int A,B;

void bfs(int a){
    visited[a]={-1,a};
    q.push(a);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==B) break;
        int n;
        for(int i=1;i<=4;i++){
            switch(i){
                case 1:
                    n=2*u%10000;
                    break;
                case 2:
                    n=(u+9999)%10000;
                    break;
                case 3:
                    n=(u%1000)*10+u/1000;
                    break;
                case 4:
                    n=u/10+(u%10)*1000;
                    break;
            }
            if(visited[n].first==0){
                visited[n]={i,u};
                q.push(n);
            }
        }
    }
}

void tracing(int cur){
    if(visited[cur].first==-1) return;
    switch(visited[cur].first){
        case 1: 
            st.push('D');
            break;
        case 2:
            st.push('S');
            break;
        case 3:
            st.push('L');
            break;
        case 4:
            st.push('R');
            break;
    }
    tracing(visited[cur].second);
}

int main()
{
    io;
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        memset(visited,'\0',sizeof(visited));
        while(!q.empty()) q.pop();
        cin>>A>>B;
        bfs(A);
        tracing(B);
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout<<'\n';
    }
    return 0;
}