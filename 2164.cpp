#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    cin>>N;
    deque<int> deq;
    for(int i=0;i<N;i++){
        deq.push_back(i+1);
    }

    while(deq.size()>1){
        deq.pop_front();
        int temp=deq.front();
        deq.pop_front();
        deq.push_back(temp);
    }
    cout<<deq.front();
    return 0;
}