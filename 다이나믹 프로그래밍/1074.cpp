#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int N,r,c;

int divide(int N,int r,int c){
    if(N<1) return 0;
    int d=pow(2,N-1), d_r=r/d, d_c=c/d;
    int pre=pow(4,N-1);
    
    if(d_r==0&&d_c==0)  pre=0;
    else pre*=d_r*2+d_c;
    return pre+divide(N-1,r-d*d_r,c-d*d_c);
}

int main()
{
    io;
    cin>>N>>r>>c;
    cout<<divide(N,r,c);
    return 0;
}
