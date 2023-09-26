#include <iostream>
#include <vector>
#include <algorithm>


#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int dp[501][501];
int map[501][501];

int dfs(int y,int x){
    if(y==M&&x==N) return 1;
    if(dp[y][x]!=-1) return dp[y][x];

    dp[y][x]=0;
    for(int k=0;k<4;k++){
        int ty=y+dy[k], tx=x+dx[k];
        if(ty>0&&tx>0&&ty<=M&&tx<=N){
            if(map[ty][tx]<map[y][x]){
                dp[y][x]=dp[y][x] + dfs(ty,tx);
            }
        }
    }
    return dp[y][x];
}

int main()
{
    io;
    cin>>M>>N;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
            dp[i][j]=-1;
        }
    }
    cout<<dfs(1,1);

    return 0;
}