#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,res=0;
    cin>>N;
    vector<vector<int>> triangle(N,vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<i+1;j++){
            cin>>triangle[i][j];
        }
    }
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=0;i<N;i++) dp[N-1][i]=triangle[N-1][i];
    for(int i=N-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            dp[i][j]=triangle[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    
    cout<<dp[0][0];

}