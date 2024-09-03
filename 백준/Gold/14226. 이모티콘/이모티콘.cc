#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);


using namespace std;

int S;
int vis[2000][2000]; //화면, 클립

int bfs(){
    //시간, 화면, 클립
    queue<tuple<int,int,int>> q;
    q.emplace(0,1,0);
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        int T=get<0>(cur);
        int D=get<1>(cur);
        int C=get<2>(cur);
        if(C==S){
            return T;
        }else{
            if(D+C<2000&&!vis[D+C][C]){
                vis[D+C][C]=true;
                q.emplace(T+1,D+C,C);
            }
            if(D-1>0&&!vis[D-1][C]){
                vis[D-1][C]=true;
                q.emplace(T+1,D-1,C);
            }
            if(D<2000&&!vis[D][D]){
                vis[D][D]=true;
                q.emplace(T+1,D,D);
            }
        }
    }    
}

int main()
{
    io;
    cin>>S;
    cout<<bfs()-1;
    return 0;
}