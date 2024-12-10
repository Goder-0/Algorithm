#include <bits/stdc++.h>

#define io ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n=-1,k=-1;
//nCk = (n-1)Ck + (n-1)C(k-1)
//nCk = n!/(k!)(n-k)!
//nCk = nC(n-k)

int main()
{
    io;
    while(cin>>n>>k){
        long long res=1;
        if(n==0&&k==0)break;

        k=min(k,n-k);
        for(int i=0;i<k;i++){
            res*=n-i;
            res/=i+1;
        }
        cout<<res<<'\n';
    }
    return 0;
}