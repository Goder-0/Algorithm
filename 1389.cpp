#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <memory.h>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int visited[101];
vector<int> friends[101];
int cebin=INT_MAX,res=0;
queue<int> q;

void bfs(int s){
    visited[s]=1;
    q.push(s);
    int r=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:friends[u]){
            if(visited[v]==0){
                visited[v]=visited[u]+1;
                q.push(v);
                r+=visited[u];
            }
        }
    }
    if(cebin>r) {
        cebin=r;
        res=s;
    }
}

int main()
{
    io;
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        memset(visited,0,sizeof(visited));
        bfs(i);
    }
    cout<<res;
    return 0;
}