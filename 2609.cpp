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
    int A,B;
    cin>>A>>B;
    cout<<gcd(A,B)<<'\n'<<A*(B/gcd(A,B));
    return 0;
}