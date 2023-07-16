#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int M,N;
    cin>>M>>N;
    vector<bool> A(N+1,true);
    A[1]=false;
    for(int i=2;i<sqrt(N)+1;i++){
        if(A[i]==true){
            int j=2;
            while(i*j<=N){
                A[i*j]=false;
                j++;
            }
        }
    }
    for(int i=M;i<=N;i++) if(A[i]) cout<<i<<'\n';
    return 0;
}