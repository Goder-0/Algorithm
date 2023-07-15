#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int K,N;
    cin>>K>>N;
    long long max=0,min=1,cen=0;
    int res=0;
    vector<int> lan(K);
    for(int i=0;i<K;i++){
        cin>>lan[i];
        if(max<lan[i]) max=lan[i];
    }
    while(min<=max){
        cen=(max+min)/2;
        int count=0;
        for(int i=0;i<K;i++){
            count+=lan[i]/cen;
        }
        if(count>=N){
            min=cen+1;
            if(res < cen) res = cen;
        }
        else if(count<N) {
            max=cen-1;
        }
    }
    cout<<res;

    return 0;
}