#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);
#define X first
#define Y second
using namespace std;

int T;
int w,h;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void spread(queue<pair<int,int>> q,vector<vector<int>> fireBuilding,vector<vector<int>> &vis){
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||ny<0||nx>=h||ny>=w) continue;
            if(vis[nx][ny]>0) continue;
            if(fireBuilding[nx][ny]==-1) continue;
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
            q.emplace(nx,ny);
        }
    }
}

int escape(pair<int,int> point,vector<vector<int>> fireBuilding,vector<vector<int>> &vis,vector<vector<int>> fireTime){
    queue<pair<int,int>> q;
    q.emplace(point);
    vis[point.X][point.Y]=1;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||ny<0||nx>=h||ny>=w) return vis[cur.X][cur.Y];
            if(vis[nx][ny]>0) continue;
            if(fireBuilding[nx][ny]<0) continue;
            if(fireTime[nx][ny]>0&&fireTime[nx][ny]<=vis[cur.X][cur.Y]+1) continue;
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
            q.emplace(nx,ny);
        }
    }
    return 0;
}

int main()
{
    io;
    cin>>T;
    for(int testcase=0;testcase<T;testcase++){
        cin>>w>>h;
        vector<vector<int>> fireBuilding(h,vector<int>(w,0));
        vector<vector<int>> fireTime(h,vector<int>(w,0));
        char c;
        pair<int,int> start;
        queue<pair<int,int>> q;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>c;
                if(c=='#') fireBuilding[i][j]=-1;
                else if(c=='*') {
                    fireBuilding[i][j]=-2;
                    q.emplace(i,j);
                    fireTime[i][j]=1;
                }
                else if(c=='@') start={i,j};
            }
        }
        vector<vector<int>> vis(h,vector<int>(w,0));
        spread(q,fireBuilding,fireTime);
        int escapeTime=escape(start,fireBuilding,vis,fireTime);
        if(escapeTime==0) cout<<"IMPOSSIBLE\n";
        else cout<<escapeTime<<'\n';
    }
    return 0;
}