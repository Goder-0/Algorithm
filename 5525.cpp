#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,M,res=0;
    cin>>N>>M;
    vector<int> counting(M);
    for(int i=0;i<M;i++){
        char c;
        cin>>c;
        if(i==0) {
            if(c=='I') counting[i]=1;
            else counting[i]=-1;
            continue;
        }
        if(c=='I'){
            if(i>=2&&counting[i-2]>0&&counting[i-1]==-1){
                if(counting[i-2]==N+1)
                    counting[i]=counting[i-2];
                else
                    counting[i]=counting[i-2]+1;
                if(counting[i]==N+1)
                    res++;
            }else counting[i]=1;
        }else{
            counting[i]=-1;
        }
    }
    cout<<res;
    return 0;
}   