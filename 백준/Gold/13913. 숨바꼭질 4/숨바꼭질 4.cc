#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int vis[100001];
int main()
{
    io;
    int N,K;
    cin>>N>>K;

    queue<pair<int,int>> q;

    vis[N]=N;
    q.emplace(0,N);
    fill(vis,vis+100001,-1);
    while(!q.empty()){
        int time = q.front().first;
        int cur = q.front().second;
        q.pop();
        
        if(cur==K){
            cout<<time<<'\n';
            stack<int> st;
            st.emplace(cur);
            for(int i=0;i<time;i++){
                cur=vis[cur];
                st.emplace(cur);
            }
            while(!st.empty()){
                cout<<st.top()<<' ';
                st.pop();
            }
            break;
        }
        int dp[] = {-1,1,cur};
        for(int i=0;i<3;i++){
            int np = cur + dp[i];
            if(np<0||np>100000) continue;
            if(vis[np]!=-1) continue;
            vis[np]=cur;
            q.emplace(time+1,np);
        }
    }
    return 0;
}