#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int K;
    cin>>K;
    vector<int> v;
    for(int i=0;i<K;i++) {
        int n;
        cin>>n;
        if(n==0) v.pop_back();
        else v.push_back(n);
    }
    int sum=0;
    for(int i:v) sum+=i;
    cout<<sum;
    
    return 0;
}