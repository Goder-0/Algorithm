#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,M;
vector<int> nums_unique;
map<int,int> num_count;
int res[9];

bool promising(int n,int depth){
    int count=0;
    for(int i=0;i<=depth;i++){
        if(res[i]==n){
            count++;
        }
    }
    if(n!=0&&num_count[n]<count)return false;
    return true;
}

void backtracking(int n,int depth){
    if(promising(n,depth)){
        if(depth==M-1){
            for(int i=0;i<M;i++) cout<<res[i]<<' ';
            cout<<'\n';
        }else{
            for(int i=0;i<nums_unique.size();i++){
                res[depth+1]=nums_unique[i];
                backtracking(nums_unique[i],depth+1);
            }
        }
    }
}

int main()
{
    io;
    cin>>N>>M;
    nums_unique.resize(N);
    for (int i = 0; i <N; i++) {
        cin>>nums_unique[i];
        num_count[nums_unique[i]]++;
    }
    sort(nums_unique.begin(),nums_unique.end());
    nums_unique.erase(unique(nums_unique.begin(),nums_unique.end()),nums_unique.end());
    backtracking(0,-1);
    return 0;
}