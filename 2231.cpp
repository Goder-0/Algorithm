#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;

    vector<int> v;
    for(int i=1;i<=N;i++){
        int n=i,M=i;
        while(n!=0){
            M+=n%10;
            n/=10;
        }
        if(M==N) {
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    if(v.size()>=1) cout<<v[0];
    else cout<<0;
    return 0;
}