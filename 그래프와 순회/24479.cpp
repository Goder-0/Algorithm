#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int sequence[100001];
bool visited[100001];
vector<int> graph[100001];

int seq=0;
void dfs(int R){
    visited[R]=true;
    sequence[R]=++seq;
    for(int x: graph[R]){
        if(visited[x]==false){
            dfs(x);
        }
    }
}

int main()
{
    io;
    int N,M,R;
    cin>>N>>M>>R;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(vector<int> &v: graph){
        sort(v.begin(),v.end());
    }
    dfs(R);
    for(int i=1;i<N+1;i++){
        cout<<sequence[i]<<'\n';
    }
    return 0;
}