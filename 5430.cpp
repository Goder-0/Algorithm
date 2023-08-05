#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int T,n,num;
    char op;
    string p;
    deque<int> deq;
    cin>>T;
    string res;
    for(int t=0;t<T;t++){
        cin>>p>>n;
        deq.clear();
        res.clear();
        bool d=false;
        cin>>op;
        for(int i=0;i<n;i++){
            cin>>num>>op;
            deq.push_back(num);
        }
        if(n==0) cin>>op;
        for(char c:p){
            if(c=='R'){
                d=!d;
            }else if(c=='D'){
                if(!deq.empty()){
                    if(d){
                        deq.pop_back();
                    }else{
                        deq.pop_front();
                    }
                }else{
                    res="error";
                    break;
                }
            }
        }
        if(res.empty()){
            res+='[';
            if(d){
                deque<int>::reverse_iterator rit=deq.rbegin();
                for(;rit!=deq.rend();rit++){
                    res+=to_string(*rit)+',';
                }
            }else{
                for(int i:deq){
                    res+=to_string(i)+',';
                }
            }
            if(!deq.empty())
                res.pop_back();
            res+=']';
        }
        cout<<res<<'\n';
    }
    return 0;
}