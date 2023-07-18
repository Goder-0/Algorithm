#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N=0,sum=0;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());

    int max_count=0,count=-1;
    int temp=arr[0];
    for(int i=0;i<N;i++){
        if(arr[i]==temp) count++;
        else{
            if(max_count<count) max_count=count;
            count=0;
        }
        temp=arr[i];
    }
    vector<int> freq;
    temp=arr[0];
    count=-1;
    for(int i=0;i<N;i++){
        if(arr[i]==temp) count++;
        else count=0;
        if(count==max_count) freq.emplace_back(arr[i]);
        temp=arr[i];
    }
    
    cout<<floor((double)sum/N+0.5)<<'\n';
    cout<<arr[(N-1)/2]<<'\n';
    if(freq.size()>1) cout<<freq[1]<<'\n';
    else cout<<freq[0]<<'\n';
    cout<<arr[N-1]-arr[0]<<'\n';
    
    return 0;
}