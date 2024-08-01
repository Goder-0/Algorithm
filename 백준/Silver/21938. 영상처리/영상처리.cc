#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second

using namespace std;
int N,M,T;
int window[1001][1001];
int vis[1001][1001];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void bfs(int x,int y){
    vis[x][y]=1;
    queue<pair<int,int>> q;
    q.emplace(x,y);
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(window[nx][ny]!=255) continue;
            if(vis[nx][ny]==1) continue;
            vis[nx][ny]=1;
            q.emplace(nx,ny);
        }
    }
}

int main()
{
    io;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int R,G,B;
            cin>>R>>G>>B;
            window[i][j]=R+G+B;
        }
    }
    cin>>T;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            window[i][j]=window[i][j]/3<T?0:255;
        }
    }
    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(vis[i][j]!=1&&window[i][j]==255){
                bfs(i,j);
                res++;
            }
        }
    }
    cout<<res;

    
    return 0;
}