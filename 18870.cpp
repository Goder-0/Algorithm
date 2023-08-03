#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int main()
{
    io;
    int N;
    cin>>N;
    vector<pair<int,int>> arr(N);
    vector<pair<int,int>> dp(N);
    for(int i=0;i<N;i++){
        arr[i].first=i;
        cin>>arr[i].second;
    }
    sort(arr.begin(),arr.end(),compare);
    dp[0].first=arr[0].first;
    dp[0].second=0;
    for(int i=1;i<N;i++){
        dp[i].first=arr[i].first;
        dp[i].second=dp[i-1].second+1;
        if(arr[i-1].second==arr[i].second) dp[i].second=dp[i-1].second;
    }
    sort(dp.begin(),dp.end());
    for(int i=0;i<N;i++) cout<<dp[i].second<<' ';

    return 0;
}