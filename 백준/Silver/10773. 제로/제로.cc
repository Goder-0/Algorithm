#include <iostream>
#include <stack>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int K,sum=0;
    cin>>K;
    stack<int> s;
    for(int i=0;i<K;i++) {
        int n;
        cin>>n;
        if(n==0) s.pop();
        else s.push(n);
    }
    while(!s.empty()) {
	    sum+=s.top();
	    s.pop();
    }
    
    cout<<sum;
    
    return 0;
}