#include <bits/stdc++.h>
#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int F,S,G,U,D;

int vis[1000001];
int UD[2];
long long res=numeric_limits<long long>::max();

void bfs(){
    queue<pair<int,long long>> q;
    q.emplace(S,0);
    vis[S]=1;
    
    while(!q.empty()){
        int floor=q.front().first;
        long long count=q.front().second;
        q.pop();
        if(floor==G) {
            res=min(res,count);
            return;
        }
        for(int i=0;i<2;i++){
            if(floor+UD[i]>F||floor+UD[i]<1||vis[floor+UD[i]]==1) continue;
            vis[floor+UD[i]]=1;
            q.emplace(floor+UD[i],count+1);
        }
    }
}
int main()
{
    io;
    cin>>F>>S>>G>>UD[0]>>UD[1];
    UD[1]=-UD[1];
    bfs();
    if(res==numeric_limits<long long>::max()){
        cout<<"use the stairs";
    }else{
        cout<<res;
    }
    return 0;
}