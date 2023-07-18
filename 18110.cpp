#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int n,sum=0,except;
    cin>>n;
    except = round((double)n*0.15);
    deque<int> deq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        deq.push_back(x);
    }
    sort(deq.begin(),deq.end());
    for(int i=0;i<except;i++){
        deq.pop_back();
        deq.pop_front();
    }
    for(int i:deq) sum+=i;
    if(n==0) cout<<0;
    else cout<<round((double)sum/(n-2*except));
    return 0;
}