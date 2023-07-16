#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,M,find;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>> A[i];
    cin>>M;
    sort(A.begin(),A.end());
    for(int i=0;i<M;i++) {
        int m,low=0,high=N-1;
        cin>>m;
        while(true){
            int mid=(low+high)/2;
            if(low>high){
                cout<<"0\n";
                break;
            }
            if(m>A[mid]){
                low=mid+1;
            }else if(m<A[mid]){
                high=mid-1;
            }else{
                cout<<"1\n";
                break;
            }
        }
    }
    return 0;
}