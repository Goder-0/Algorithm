#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

int M,N;
int graph[1001][1001];
int visited[1001][1001];
queue<pair<int,int>> q;
void bfs(){
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int next_y=u.first+dy[i],next_x=u.second+dx[i];
            if(next_y<=N&&next_x<=M&&next_y>0&&next_x>0&&visited[next_y][next_x]==false&&graph[next_y][next_x]!=-1){
                visited[next_y][next_x]=visited[u.first][u.second]+1;
                q.push(make_pair(next_y,next_x));
            }
        }
    }
}


int main()
{
    io;
    int res=0;
    cin>>M>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>graph[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(graph[i][j]==1&&visited[i][j]==false){
                q.push(make_pair(i,j));
                visited[i][j]=1;
            }
        }
    }
    bfs();

    bool poss=true;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(res<visited[i][j]) res=visited[i][j]-1;
            if(graph[i][j]!=-1&&visited[i][j]==0){
                poss=false;
            }
        }
    }
    if(poss) cout<<res;
    else cout<<-1;

    return 0;
}