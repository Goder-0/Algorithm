#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N;
    priority_queue<int> pq;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(x==0){
            if(pq.empty())cout<<"0\n";
            else {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }else pq.push(x);
    }
    return 0;
}