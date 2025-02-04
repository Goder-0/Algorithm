#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
using namespace std;

int N,M,R,C;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int room_map[1001][1001];
int res=INT_MAX;
int vis[1001][1001];

void bfs(){
    queue<pair<int,int>> q;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(room_map[i][j]==-1) {
                q.emplace(i,j);
                vis[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        
        if(room_map[cur.X][cur.Y]>0){
            res = min(res,room_map[cur.X][cur.Y]*(vis[cur.X][cur.Y]-1));
        }
        
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<1||nx>N||ny<1||ny>M) continue;
            if(vis[nx][ny]) continue;
            q.emplace(nx,ny);
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
        }
    }
}

int main()
{
    io;
    cin>>N>>M>>R>>C;
    int x,y,p;
    for(int i=0;i<R;i++){
        cin>>x>>y>>p;
        room_map[x][y]=p;
    }
    for(int i=0;i<C;i++){
        cin>>x>>y;
        room_map[x][y]=-1;
    }
    bfs();
    cout<<res;

    return 0;
}