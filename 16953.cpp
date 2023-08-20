#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

queue<int> q;
int A,B;
map<int,long long> visited;
long long res=1e+9;

void bfs(){
    q.push(A);
    visited[A]=1;
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        if(visited[u]<res){
            if(u==B) res=visited[u];
            else{
                if(u*2<=B&&visited[u*2]==0) {
                    q.push(u*2);
                    visited[u*2]=visited[u]+1;
                }
                if(u*10+1<=B&&visited[u*10+1]==0) {
                    q.push(u*10+1);
                    visited[u*10+1]=visited[u]+1;
                }
            }
        }
    }
}

int main()
{
    io;
    cin>>A>>B;
    bfs();
    if(res!=1e+9) cout<<res;
    else cout<<-1;
    return 0;
}