#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int gcd(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    io;
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N,M,x,y;
        bool p=true;
        cin>>N>>M>>x>>y;
        int lcm=N*(M/gcd(N,M));
        for(int i=0;i<lcm;i+=N){
            if((i+x-y)%M==0){
                cout<<i+x<<"\n";
                p=false;
                break;
            }
        }
        if(p) cout<<"-1\n";
    }

    return 0;
}


