#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool compare(pair<int,int> a,pair<int,int>b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
    io;
    int N,res=1;
    cin>>N;
    vector<pair<int,int>> meet(N);
    for(int i=0;i<N;i++){
        cin>>meet[i].first>>meet[i].second;
    }
    sort(meet.begin(),meet.end(),compare);

    int finish=meet[0].second;
    for(int i=1;i<N;i++){
        if(finish<=meet[i].first){
            res++;
            finish=meet[i].second;
        }    
    }
    cout<<res;
    return 0;
}   