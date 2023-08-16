#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
int nums[9];
int res[9];

bool promising(int n,int depth){
    for(int i=0;i<depth;i++){
        if(res[i]==n) return false;
    }
    return true;
}

void backtracking(int n,int depth){
    if(promising(n,depth)){
        if(depth==M-1){
            for(int i=0;i<M;i++){
                cout<<res[i]<<' ';
            }
            cout<<'\n';
        }else{
            for(int i=0;i<N;i++){
                res[depth+1]=nums[i];
                backtracking(nums[i],depth+1);
            }
        }
    }
}

int main()
{
    io;
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>nums[i];
    sort(&nums[0],&nums[0]+N);
    backtracking(0,-1);
    return 0;
}