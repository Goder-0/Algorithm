#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool pos[26][26];
int visited[26][26];
queue<pair<int,int>> q; 
int s=0;
vector<int> hc;
int N;

void bfs(int x,int y){
    visited[x][y]=true;
    s=1;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<int,int> u=q.front();
        q.pop();
        if(pos[u.first][u.second]){
            if(u.first+1<=N&&pos[u.first+1][u.second]&&visited[u.first+1][u.second]==false){
                visited[u.first+1][u.second]=true;
                q.push(make_pair(u.first+1,u.second));
                s++;
            }
            if(u.second+1<=N&&pos[u.first][u.second+1]&&visited[u.first][u.second+1]==false){
                visited[u.first][u.second+1]=true;
                q.push(make_pair(u.first,u.second+1));
                s++;
            }if(u.first-1>=1&&pos[u.first-1][u.second]&&visited[u.first-1][u.second]==false){
                visited[u.first-1][u.second]=true;
                q.push(make_pair(u.first-1,u.second));
                s++;
            }
            if(u.second-1>=1&&pos[u.first][u.second-1]&&visited[u.first][u.second-1]==false){
                visited[u.first][u.second-1]=true;
                q.push(make_pair(u.first,u.second-1));
                s++;
            }
        }
    }
    hc.push_back(s);
}


int main()
{
    io;
    cin>>N;
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            char c;
            cin>>c;
            if(c=='1') pos[i][j]=true;
            else pos[i][j]=false;
        }
    }

    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            if(pos[i][j]&&visited[i][j]==false){
                bfs(i,j);
            }
        }
    }
    cout<<hc.size()<<'\n';
    sort(hc.begin(),hc.end());
    for(int c:hc) cout<<c<<'\n';
    return 0;
}