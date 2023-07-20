#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<int> graph[1001];
bool visited[1001][2];
deque<int> q;

void dfs(int V){
    visited[V][0]=true;
    cout<<V<<' ';
    for(int u:graph[V]){
        if(visited[u][0]==false){
            dfs(u);
        }
    }
}

void bfs(int V){
    visited[V][1]=true;
    q.push_back(V);
    cout<<V<<' ';
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(int v:graph[u]){
            if(visited[v][1]==false){
                visited[v][1]=true;
                q.push_back(v);
                cout<<v<<' ';
            }
        }
    }
}

int main()
{
    io;
    int N,M,V;
    cin>>N>>M>>V;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(vector<int> &v:graph){
        sort(v.begin(),v.end());
    }

    dfs(V);
    cout<<'\n';
    bfs(V);
    return 0;
}