#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

queue<int> q;
int visited[100001];
int N,K;

void bfs(int n){
    q.push(n);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(2*u<=100000){
            if(visited[2*u]==0&&u!=2*u){
                visited[2*u]=visited[u]+1;
                q.push(2*u);
            }
            else if(visited[2*u]>visited[u]+1){
                visited[2*u]=visited[u]+1;
            }
        }
        if(u+1<=100000){
            if(visited[u+1]==0){
                visited[u+1]=visited[u]+1;
                q.push(u+1);
            }
            else if(visited[u+1]>visited[u]+1){
                visited[u+1]=visited[u]+1;
            }
        }
        if(u-1>=0){
            if(visited[u-1]==0){
                visited[u-1]=visited[u]+1;
                q.push(u-1);
            }
            else if(visited[u-1]>visited[u]+1){
                visited[u-1]=visited[u]+1;
            }
        }
    }
}

int main()
{
    io;
    cin>>N>>K;
    bfs(N);
    if(N==K) cout<<0;
    else cout<<visited[K];
    return 0;
}