#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
int nums[9];
int res[9];

void backtracking(int n,int depth,int pre){
    if(pre<=n){
        if(depth==M){
            for(int i=1;i<=M;i++) cout<<res[i]<<' ';
            cout<<'\n';
        }else{
            for(int i=1;i<=N;i++){
                res[depth+1]=nums[i];
                backtracking(nums[i],depth+1,res[depth]);
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
    sort(&nums[1],&nums[1]+N);
    backtracking(0,0,0);

    return 0;
}