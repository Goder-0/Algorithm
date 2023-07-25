#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
vector<int> nums(9);

bool promising(int n, int idx){
    for(int i=1;i<idx;i++){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }
    return true;
}

void backtracking(int n, int idx){
    if(promising(n,idx)){
        if(idx==M){
            for(int i=1;i<=M;i++){
                cout<<nums[i]<<' ';
            }
            cout<<'\n';
        }else{
            for(int i=1;i<=N;i++){
                nums[idx+1]=i;
                backtracking(i,idx+1);
            }
        }
    }
}


int main()
{
    io;
    cin>>N>>M;
    backtracking(0,0);
    return 0;
}