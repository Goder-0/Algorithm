#include <iostream>
#include <vector>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main(){
    io;
    int N;
    cin>>N;
    int n=0,res=0;
    while(n!=N){
        res++;
        int temp=res;

        while(temp!=0){
            if(temp%1000==666){
                n++;
                break;
            }
            else temp/=10;
        }
    }
    cout<<res;
}