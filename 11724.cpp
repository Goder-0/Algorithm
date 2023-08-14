#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<int> graph[499501];
bool visited[1001];
queue<int> q;
void bfs(int R){
    visited[R]=true;
    q.push(R);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            if(visited[v]==false){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}



int main()
{
    io;
    int N,M,res=0;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        if(visited[i]==false){
            bfs(i);
            res++;
        }
    }
    cout<<res;
    return 0;
}