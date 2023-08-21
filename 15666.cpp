#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
int nums[9];
int res[9];
bool visited[9];
bool promising(int n,int depth){
    if(res[depth-1]<=n)return true;
    return false;
}

void backtracking(int n,int depth){
    if(promising(n,depth)){
        if(depth==M){
            for(int i=1;i<=M;i++){
                cout<<res[i]<<' ';
            }
            cout<<'\n';
        }else{
            fill(visited,visited+9,false);
            for(int i=1;i<=N;i++){
                if(visited[i]==false){
                    for(int j=1;j<=N;j++){
                        if(j!=i&&nums[i]==nums[j]){
                            visited[j]=true;
                        }
                    }
                    res[depth+1]=nums[i];
                    backtracking(nums[i],depth+1);
                }
            }
        }
    }
}

int main()
{
    io;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>nums[i];
    }
    sort(nums+1,nums+N+1);
    backtracking(0,0);
    return 0;
}