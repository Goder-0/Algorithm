#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <climits>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool graph[1001][1001];
int visited[1001][1001][2];
int res=INT_MAX;
queue<pair<pair<int,int>,int>> q;
int N,M;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void bfs(){
    visited[1][1][0]=1;
    q.push(make_pair(make_pair(1,1),0));
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        int cy=u.first.first,cx=u.first.second,cb=u.second;

        if(cy==N&&cx==M&&res>visited[cy][cx][cb])
            res=visited[cy][cx][cb];
        
        for(int i=0;i<4;i++){
            int y=cy+dy[i],x=cx+dx[i];
            if(y>0&&y<=N&&x>0&&x<=M){
                if(graph[y][x]==true&&visited[y][x][cb]==0){
                    visited[y][x][cb]=visited[cy][cx][cb]+1;
                    q.push(make_pair(make_pair(y,x),cb));
                }
                if(graph[y][x]==false&&cb==0){
                    visited[y][x][1]=visited[cy][cx][cb]+1;
                    q.push(make_pair(make_pair(y,x),1));
                }
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
            if(c=='0') graph[i][j]=true;
            else graph[i][j]=false;
        }
    }
    
    bfs();
    
    if(res==INT_MAX) cout<<-1;
    else cout<<res;
    

    return 0;
}