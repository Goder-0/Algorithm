#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define io ios::sync_with_stdio(false); cin.tie(0);

char graph[601][601];
bool visited[601][601];

using namespace std;

queue<pair<int,int>> q;

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int N,M;

int res=0;

void bfs(int y,int x){
    visited[y][x]=true;
    q.push({y,x});
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        if(graph[u.first][u.second]=='P') res++;
        for(int i=0;i<4;i++){
            int new_y=u.first+dy[i],new_x=u.second+dx[i];
            
            if(new_y>N||new_y<1||new_x>M||new_x<1||graph[new_y][new_x]=='X') continue;
            
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
    int x,y;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>graph[i][j];
            if(graph[i][j]=='I'){
                y=i;
                x=j;
            }
        }
    }
    bfs(y,x);

    if(res!=0) cout<<res;
    else cout<<"TT";
    return 0;
}