#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool graph[101][101];
int visited[101][101];
queue<pair<int,int>> q;
int N,M;

void bfs(int y,int x){
    visited[y][x]=1;
    int todo[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    q.push(make_pair(y,x));
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        bool increase=false;
        for(int i=0;i<4;i++){
            int yt=u.first+todo[i][0],xt=u.second+todo[i][1];
            if(yt <=100 && xt <=100 && graph[yt][xt] && visited[yt][xt]==0){
                visited[yt][xt]=visited[u.first][u.second]+1;
                q.push(make_pair(yt,xt));
            }
        }
    }
}

int main()
{
    io;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            char c;
            cin>>c;
            if(c=='1') graph[i][j]=true;
        }
    }
    
    bfs(1,1);
    cout<<visited[N][M];
    return 0;
}