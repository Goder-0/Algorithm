#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int room[101][101];
int vis[101][101];

int N,M;
vector<pair<int,int>> lights[101][101];

bool is_conn(pair<int, int> point) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = point.X + dx[dir];
        int ny = point.Y + dy[dir];
        if (nx<1||ny<1||nx>N||ny>N) continue;
        if (vis[nx][ny]) return 1;
    }
    return 0;
}

int lightOn(){
    int c=0;
    queue<pair<int,int>>q;
    room[1][1]=true;
    vis[1][1]=true;
    q.emplace(1,1);
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(auto point:lights[cur.X][cur.Y]){
            if(vis[point.X][point.Y]) continue;
            if(!room[point.X][point.Y]){
                if(is_conn(point)){
                    vis[point.X][point.Y]=true;
                    q.emplace(point);
                }
                room[point.X][point.Y]=true;
            }
        }
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<1||ny<1||nx>N||ny>N) continue;
            if(!room[nx][ny]) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny]=true;
            q.emplace(nx,ny);
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(room[i][j]) c++;
    
    
    return c;
}

int main()
{
    io;
    cin>>N>>M;
    int x,y,a,b;
    for(int i=0;i<M;i++){
        cin>>x>>y>>a>>b;
        lights[x][y].emplace_back(a,b);
    }
    cout<<lightOn();

    return 0;
}