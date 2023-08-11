#include <iostream>
#include <vector>
#include <algorithm>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;
    vector<vector<int>> graph(N+1,vector<int>(N+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>graph[i][j];
            if(graph[i][j]==0) graph[i][j]=101;
        }
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(graph[i][j]!=101)cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<'\n';
    }
    return 0;
}