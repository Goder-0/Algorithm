#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,M;
    int x1,x2,y1,y2;
    cin>>N>>M;
    vector<vector<int>> nums(N+1,vector<int>(N+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>nums[i][j];
            nums[i][j]+=nums[i][j-1];
        }
    }
    for(int k=0;k<M;k++){
        cin>>x1>>y1>>x2>>y2;
        int res=0;
        for(int i=x1;i<=x2;i++){
            res+=nums[i][y2]-nums[i][y1-1];
        }
        cout<<res<<'\n';
    }

    return 0;
}