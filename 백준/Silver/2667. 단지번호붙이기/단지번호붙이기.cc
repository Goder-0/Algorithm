#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define io ios::sync_with_stdio(false); cin.tie(0);
#define X first
#define Y second


using namespace std;

bool pos[26][26];
int vis[26][26];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue<pair<int,int>> q; 
vector<int> hc;
int N;

int bfs(int x,int y){
    vis[x][y]=1;
    int count=1;
    q.emplace(x,y);
    while(!q.empty()){
        pair<int,int> cur=q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx>=N||nx<0||ny>=N||ny<0) continue;
            if(!pos[nx][ny]) continue;
            if(vis[nx][ny]==1) continue;
            vis[nx][ny]=1;
            q.emplace(nx,ny);
            count++;
        }
    }
    return count;
}


int main()
{
    io;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c;
            cin>>c;
            if(c=='1') pos[i][j]=true;
            else pos[i][j]=false;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(pos[i][j]&&vis[i][j]==0){
                hc.emplace_back(bfs(i,j));
            }
        }
    }
    sort(hc.begin(),hc.end());
    cout<<hc.size()<<'\n';
    for(int i:hc) cout<<i<<'\n';
    return 0;
}