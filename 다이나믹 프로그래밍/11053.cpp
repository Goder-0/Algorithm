#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<int> input(N);
    vector<int> dp(N,0);
    for(int i=0;i<N;i++) cin>>input[i];
    int res=0;
    dp[0]=1;
    for(int i=0;i<N;i++){
        int maxDp=0;
        for(int j=0;j<i;j++){
            if(input[j]<input[i]&&dp[j]>maxDp)
                maxDp=dp[j];
        }
        dp[i]=maxDp+1;
        res=max(dp[i],res);
    }
    
    cout<<res;
}