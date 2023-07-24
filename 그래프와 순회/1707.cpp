#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int check[20001];
bool visited[20001];
vector<int> graph[20001];
queue<int> q;

bool dfs(int start,int c){
    check[start]=c;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int v:graph[u]){
            if(check[u]==check[v]){
                return false;
            }
            if(visited[v]==false){
                visited[v]=true;
                check[v]=check[u]*-1;
                q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    io;
    int K,V,E;
    cin>>K;
    for(int t=0;t<K;t++){
        cin>>V>>E;
        for(int i=1;i<=V;i++) graph[i].clear();
        memset(check,0,sizeof(check));
        memset(visited,0,sizeof(visited));
        while(!q.empty())q.pop();
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool poss=true;
        for(int i=1;i<=V;i++){
            if(!poss) break;
            if(visited[i]==false)
                poss=dfs(i,-1);
        }
        if(poss) cout<<"YES\n";
        else cout<<"NO\n";

    }


    return 0;
}