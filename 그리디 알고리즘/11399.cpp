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
    vector<int> time(N);
    for(int i=0;i<N;i++){
        cin>>time[i];
    }
    sort(time.begin(),time.end());
    int total=0,res=0;
    for(int i=0;i<N;i++){
        total+=time[i];
        res+=total;
    }
    cout<<res;
    return 0;
}