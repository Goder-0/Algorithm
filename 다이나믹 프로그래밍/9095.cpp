#include<iostream>
#include<vector>

using namespace std;
int main(void){
    int N;
    vector<int> dp(10, 0);
    int input;
    cin>>N;
    
    dp[0]=1; dp[1]=2; dp[2]=4;
    for(int j=3;j<10;j++){
        dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
    }

    for(int i=0;i<N;i++) {
        cin>>input;
        cout<<dp[input-1]<<endl;
    }
}