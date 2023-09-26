#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;



vector<pair<int,int>> line;

int main()
{
    io;
    int N;
    int dp[501];
    int max_line=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int u,v;
        cin>>u>>v;
        line.emplace_back(u,v);
    }
    sort(line.begin(),line.end());
    
    for(int i=0;i<N;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(line[i].second>line[j].second){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        max_line=max(dp[i],max_line);
    }

    cout<<N-max_line;


    return 0;
}