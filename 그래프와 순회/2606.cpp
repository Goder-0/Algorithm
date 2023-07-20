#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool visited[101];
vector<int> graph[101];
deque<int> q;
int res=-1;

void bfs(int R){
    visited[R]=true;
    res++;
    q.push_back(R);
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(int v:graph[u]){
            if(visited[v]==false){
                visited[v]=true;
                res++;
                q.push_back(v);
            }
        }
    }
}

int main()
{
    io;
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    cout<<res<<'\n';

    return 0;
}