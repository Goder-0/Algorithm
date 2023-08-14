#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int n,res=5;
    cin>>n;
    
    for(int i=sqrt(n);i>=1&&res>1;i--){
        int a=i*i;
        if(n==a) {
            res=1;
            break;
        }
        for(int j=sqrt(n-a);j>=1&&res>2;j--){
            int b=j*j;
            if(n==a+b) {
                res=2;
            }
            for(int k=sqrt(n-a-b);k>=1&&res>3;k--){
                int c=k*k;
                if(n==a+b+c) {
                    res=3;
                }
                for(int l=sqrt(n-a-b-c);l>=1&&res>4;l--){
                    int d=l*l;
                    if(n==a+b+c+d) {
                        res=4;
                    }
                }
            }
        }
    }

    cout<<res;
    return 0;
}