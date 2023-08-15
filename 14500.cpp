#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
int N,M;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int graph[501][501];
int res=0;
pair<int,int> visited[5];

void dfs(int y,int x,int depth,int sum,bool back){

    if(depth==3&&back==false||depth==4&&back) {
        if(res<sum) res=sum;
        return;
    }
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<1||ny>N||nx<1||nx>M) continue;
        bool poss=true,b=back;
        for (int j = 0; j < depth; j++){
            if(visited[j].first==ny&&visited[j].second==nx){
                if(b) poss=false;
                else b=true;
                break;
            }
        }
        if(poss==false) continue;
        visited[depth+1]={ny,nx};
        dfs(ny,nx,depth+1,back!=b?sum:sum+graph[ny][nx],b);
    }
}

int main()
{
    io;
    cin>>N>>M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            cin>>graph[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            visited[0]={i,j};
            dfs(i,j,0,graph[i][j],false);
        }
    }

    cout<<res;

    return 0;
}