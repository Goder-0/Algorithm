#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int dx[]={-2,-1,1,2, 2, 1,-1,-2};
int dy[]={ 1, 2,2,1,-1,-2,-2,-1};

int visited[300][300];
queue<pair<int,int>> q;

void bfs(int now_y,int now_x,int l){
    visited[now_y][now_x]=1;
    q.push(make_pair(now_y,now_x));
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int y=u.first+dy[i],x=u.second+dx[i];
            if(y<l&&y>=0&&x>=0&&x<l){
                if(visited[y][x]==0){
                    visited[y][x]=visited[u.first][u.second]+1;
                    q.push(make_pair(y,x));
                }else visited[y][x]=min(visited[y][x],visited[u.first][u.second]+1);
            }
        }
    }
}

int main()
{
    io;
    int T,l,now_x,now_y,todo_x,todo_y;
    cin>>T;
    for(int t=0;t<T;t++){
        q=queue<pair<int,int>>();
        memset(visited,0,sizeof(visited));

        cin>>l>>now_y>>now_x>>todo_y>>todo_x;

        bfs(now_y,now_x,l);
        cout<<visited[todo_y][todo_x]-1<<'\n';
    }

    return 0;
}