#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,res=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        if(n!=1)
            res++;
        for(int j=2;j<=sqrt(n);j++){
            if(n%j==0) {
                res--;
                break;
            }
        }
    }
    cout<<res;
    return 0;
}