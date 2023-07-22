#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;


bool visited[50][50];
bool graph[50][50];
int c=0;
void dfs(int y,int x){
    visited[y][x]=true;
    int todo[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(int i=0;i<4;i++){
        int yt=y+todo[i][0],xt=x+todo[i][1];
        if(yt>=0 && yt<50 && xt>=0 &&xt<50 && graph[yt][xt] && visited[yt][xt]==false ){
            dfs(yt,xt);
        }
    }

}

int main()
{
    io;
    int T,N,M,K,X,Y;
    cin>>T;
    for(int t=0;t<T;t++){
        memset(visited,0,sizeof(visited));
        memset(graph,0,sizeof(graph));
        c=0;
        cin>>M>>N>>K;
        for(int k=0;k<K;k++){
            cin>>X>>Y;
            graph[Y][X]=true;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(graph[i][j]&&visited[i][j]==false){
                    dfs(i,j);
                    c++;
                }
            }
        }
        cout<<c<<'\n';
    }

    return 0;
}