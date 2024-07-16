#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

using namespace std;
int N,M;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int vis[300][300];

void melt(vector<vector<int>>& graph){
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]==0){
                q.emplace(i,j);
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(vis[nx][ny]>0) continue;
            if(graph[nx][ny]!=0)
                graph[nx][ny]--;
        }
    }
}

int count(vector<vector<int>> graph){
    queue<pair<int,int>> q;
    int area=0; 
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            if(graph[x][y]!=0 && !vis[x][y]){
                area++;
                vis[x][y]=1;
                q.emplace(x,y);
                while(!q.empty()){
                    auto cur=q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx=cur.X+dx[dir];
                        int ny=cur.Y+dy[dir];
                        if(nx<0||ny<0||nx>=N||ny>=M) continue;
                        if(vis[nx][ny]>0) continue;
                        if(graph[nx][ny]==0) continue;
                        vis[nx][ny]=1;
                        q.emplace(nx,ny);
                    }
                }
            }
        }
    }
    
    return area;
}

int main()
{
    io;
    cin>>N>>M;
    vector<vector<int>> graph(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>graph[i][j];
        }
    }
    int year=0, area=0;
    while(area<2)
    {
        for(int i=0;i<N;i++) fill(vis[i],vis[i]+M,0);
        melt(graph);
        year++;
        area=count(graph);
        if(area==0) {
            year=0;
            break;
        }
    }
    cout<<year;
    return 0;
}