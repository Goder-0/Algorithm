#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int mov[101];
int visited[101];
queue<int> q;
void bfs(int start){
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(mov[u]!=0){
            visited[mov[u]]=visited[u];
            q.push(mov[u]);
        }
        else{
            for(int i=1;i<=6&&u+i<=100;i++){
                if(visited[u+i]>visited[u]+1||visited[u+i]==0){
                    visited[u+i]=visited[u]+1;
                    q.push(u+i);
                }
            }
        }
    }
}


int main()
{
    io;
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N+M;i++){
        int x,y;
        cin>>x>>y;
        mov[x]=y;
    }

    bfs(1);
    cout<<visited[100]-1;
    

    return 0;
}