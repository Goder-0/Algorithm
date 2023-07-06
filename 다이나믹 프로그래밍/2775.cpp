#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(14,0);

int live(int a, int b){
    for(int j=0;j<b;j++) dp[j]=j+1;

    for(int i=0;i<a;i++){
        int sum=0;
        for(int j=0;j<b;j++){
            sum+=dp[j];
            dp[j]=sum;
        }
    }
    return dp[b-1];
}

int main(void){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int a,b;
        cin>>a>>b;
        cout<<live(a,b)<<endl;
    }
}