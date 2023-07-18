#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;
    vector<vector<int>> arr(N,vector<int>(2));
    for(int i=0;i<N;i++){
        cin>>arr[i][0]>>arr[i][1];
    }

    for(int i=0;i<N;i++){
        int count=1;
        for(int j=0;j<N;j++){
            if(i!=j){
                if(arr[i][0]<arr[j][0]&&arr[i][1]<arr[j][1]){
                    count++;
                }
            }
        }
        cout<<count<<' ';
    }
    return 0;
}