#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,M;
    cin>>N>>M;
    vector<int> nums(N+1);
    for(int i=1;i<=N;i++) {
        cin>>nums[i];
        nums[i]+=nums[i-1];
    }
    for(int m=0;m<M;m++){
        int i,j;
        cin>>i>>j;
        cout<<nums[j]-nums[i-1]<<'\n';
    }
    return 0;
}