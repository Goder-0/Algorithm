#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int visited[100001];
vector<int> graph[100001];
int N,M,R,seq=0;
deque<int> q;

void bfs(int R){
    visited[R]=++seq;
    q.push_back(R);
    while(!q.empty()){
        int u=q.front();
        q.pop_front();
        for(int v:graph[u]){
            if(visited[v]==0){
                visited[v]=++seq;
                q.push_back(v);
            }
        }
    }


}


int main()
{
    io;
    cin>>N>>M>>R;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(vector<int> &v:graph){
        sort(v.begin(),v.end(),greater<int>());
    }

    bfs(R);

    for(int i=1;i<N+1;i++){
        cout<<visited[i]<<'\n';
    }


    return 0;
}