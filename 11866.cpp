#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int N,K;
    cin>>N>>K;
    deque<int> deq;
    for(int i=1;i<=N;i++){
        deq.push_back(i);
    }
    string s="<";
    while(!deq.empty()){
        if(deq.size()>K-1){
            rotate(deq.begin(),deq.begin()+K-1,deq.end());
        }
        else{
            for(int i=0;i<K-1;i++){
                rotate(deq.begin(),deq.begin()+1,deq.end());
            }
        }
        s+=to_string(deq.front())+", ";
        deq.pop_front();
    }
    s.pop_back();
    s.pop_back();
    cout<<s<<'>';
    return 0;
}