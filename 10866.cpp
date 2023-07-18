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
    string s;
    for(int i=0;i<N;i++){
        int x;
        cin>>s;
        if(s=="push_front"){
            cin>>x;
            deq.push_front(x);
        }else if(s=="push_back"){
            cin>>x;
            deq.push_back(x);        
        }else if(s=="pop_front"){
            if(!deq.empty()){
                cout<<deq.front()<<'\n';
                deq.pop_front();
            }else cout<<"-1\n";
        }else if(s=="pop_back"){
            if(!deq.empty()){
                cout<<deq.back()<<'\n';
                deq.pop_back();
            }else cout<<"-1\n";
        }else if(s=="size"){
            cout<<deq.size()<<'\n';
        }else if(s=="empty"){
            cout<<deq.empty()<<'\n';
        }else if(s=="front"){
            if(!deq.empty()){
                cout<<deq.front()<<'\n';
            }else cout<<"-1\n";
        }else if(s=="back"){
            if(!deq.empty()){
                cout<<deq.back()<<'\n';
            }else cout<<"-1\n";
        }
    }
    return 0;
}