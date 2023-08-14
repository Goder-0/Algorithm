#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
int N;

char graph[101][101];
bool visited[101][101];
queue<pair<int,int>> q;
int res_rgno=0,res=0;

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

void rgNoDiff(int y,int x){
    visited[y][x]=true;
    q.push({y,x});
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int new_y=u.first+dy[i], new_x=u.second+dx[i];

            if(new_y<1||new_y>N||new_x<1||new_x>N) continue;
            if(graph[new_y][new_x]!=graph[u.first][u.second]){
                if(graph[new_y][new_x]=='B'||graph[u.first][u.second]=='B') continue;
            }
            if(visited[new_y][new_x]==false){
                visited[new_y][new_x]=true;
                q.push({new_y,new_x});
            }
        }
    }
}

void bfs(int y,int x){
    visited[y][x]=true;
    q.push({y,x});
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int new_y=u.first+dy[i], new_x=u.second+dx[i];

            if(new_y<1||new_y>N||new_x<1||new_x>N) continue;
            if(graph[new_y][new_x]!=graph[u.first][u.second]) continue;
            if(visited[new_y][new_x]==false){
                visited[new_y][new_x]=true;
                q.push({new_y,new_x});
            }
        }
    }
}

int main()
{
    io;
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>graph[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(visited[i][j]==false){
                bfs(i,j);
                res++;
            }
        }
    }
    
    memset(visited,false,sizeof(visited));
    while(!q.empty())q.pop();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(visited[i][j]==false){
                rgNoDiff(i,j);
                res_rgno++;
            }
        }
    }

    cout<<res<<' '<<res_rgno;
    return 0;
}