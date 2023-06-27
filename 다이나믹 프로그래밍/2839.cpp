#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int N;
    cin>>N;
    int x=N/5+1;
    vector<vector<int>> dp(x+1,vector<int>(N+1,0));
    for(int i=3;i<=N;i++)if(i%3==0) dp[0][i]=i/3;
    for(int i=1;i<=x;i++){
        for(int j=3;j<=N;j++){
            dp[i][j]=dp[i-1][j];
            if(j==5)dp[i][j]=1;
            if(j-5*i>0&&dp[i][j-5*i]) dp[i][j]=dp[i][j-5*i]+i;
        }
    }
    if(dp[x][N]==0) cout<<-1;
    else cout<<dp[x][N];
}
