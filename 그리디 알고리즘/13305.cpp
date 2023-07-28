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
    vector<int> dist(N-1);
    vector<int> price(N);
    for(int i=0;i<N-1;i++) cin>>dist[i];
    for(int i=0;i<N;i++) cin>>price[i];
    int i=0;
    long long pay=0;
    while(i<N-1){
        int j=i+1;
        long long totalDist=dist[i];
        while(j<N-1&&price[i]<price[j]) {
            totalDist+=dist[j];
            j++;
        }
        pay+=price[i]*totalDist;
        i=j;
    }
    cout<<pay;
    return 0;
}