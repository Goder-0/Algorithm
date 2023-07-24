#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M,H;

int res=0;
int visited[100][100][100];
int graph[100][100][100];
queue<pair<int,pair<int,int>>> q;

int dz[]={0,0,0,0,1,-1};
int dx[]={0,1,0,-1,0,0};
int dy[]={1,0,-1,0,0,0};

void bfs(){
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int h=u.first+dz[i];
            int n=u.second.first+dy[i];
            int m=u.second.second+dx[i];
            if(h>=0&&h<H&&n>=0&&n<N&&m>=0&&m<M&&graph[h][n][m]!=-1&&visited[h][n][m]==0){
                visited[h][n][m]=visited[u.first][u.second.first][u.second.second]+1;
                q.push(make_pair(h,make_pair(n,m)));
            }
        }
    }
}

int main()
{
    io;
    cin>>M>>N>>H;
    for(int h=0;h<H;h++){
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                cin>>graph[h][n][m];
            }
        }
    }

    for(int h=0;h<H;h++){
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                if(graph[h][n][m]==1&&visited[h][n][m]==0){
                    q.push(make_pair(h,make_pair(n,m)));
                    visited[h][n][m]=1;
                }
            }
        }
    }

    bfs();

    bool poss=true;
    for(int h=0;h<H;h++){
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                if(graph[h][n][m]!=-1&&visited[h][n][m]==0){
                    poss=false;
                }
                if(visited[h][n][m]>res) res=visited[h][n][m];
            }
        }
    }
    if(poss) cout<<res-1;
    else cout<<-1;

    return 0;
}