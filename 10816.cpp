#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,M;
    cin>>N;
    vector<int> arr(N);
    unordered_map<int,int> map(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
        map[arr[i]]++;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int n;
        cin>>n;
        cout<<map[n]<<' ';
    }
    return 0;
}