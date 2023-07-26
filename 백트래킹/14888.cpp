#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<int> nums;
vector<int> op(4);
int N;
int res_max=-1000000000,res_min=1000000000;
int res=0;
bool promising(){

}

void backtracking(int idx){
    if(idx==N-1){
        if(res_max<res){
            res_max=res;
        }
        if(res_min>res){
            res_min=res;
        }
    }else{
        if(op[0]>0){
            res+=nums[idx+1];
            op[0]--;
            backtracking(idx+1);
            op[0]++;
            res-=nums[idx+1];
        }
        if(op[1]>0){
            res-=nums[idx+1];
            op[1]--;
            backtracking(idx+1);
            op[1]++;
            res+=nums[idx+1];
        }
        if(op[2]>0){
            res*=nums[idx+1];
            op[2]--;
            backtracking(idx+1);
            op[2]++;
            res/=nums[idx+1];
        }
        if(op[3]>0){
            int rem=res%nums[idx+1];
            res/=nums[idx+1];
            op[3]--;
            backtracking(idx+1);
            op[3]++;
            res=res*nums[idx+1]+rem;
        }
    }
}

int main()
{
    io;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    for(int i=0;i<4;i++) cin>>op[i];
    res=nums[0];
    backtracking(0);

    cout<<res_max<<'\n'<<res_min;
    return 0;
}