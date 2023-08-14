#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
int graph[1001][1001];
int visited[1001][1001];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
queue<pair<int,int>> q;
void bfs(int y,int x){
    visited[y][x]=1;
    q.push(make_pair(y,x));
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int gy=u.first+dy[i],gx=u.second+dx[i];
            if(gy<1||gy>N||gx>M||gx<1||graph[gy][gx]==0) continue;
            if(visited[gy][gx]==0){
                visited[gy][gx]=visited[u.first][u.second]+1;
                q.push(make_pair(gy,gx));
            }
        }
    }
}

int main()
{
    io;
    int x,y;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>graph[i][j];
            if(graph[i][j]==2) {
                y=i;
                x=j;
            }
            else if(graph[i][j]==0) 
                visited[i][j]=1;
        }
    }
    bfs(y,x);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<visited[i][j]-1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}