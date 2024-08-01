#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{
    io;
    int A,T,B;
    cin>>A>>T>>B;
    int total=0,n=2;
    while(true){
        if((total+4+2*n)/2>=T) break;
        total+=4+2*n;
        n++;
    }
    int res=total;
    int gap=T-total/2;
    if(gap>0&&gap<=2){
        res+=B+gap*3/2-1;
    }else{
        res+=n*B+gap+1;
    }

    cout<<res%A;
    return 0;
}