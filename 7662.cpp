#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int T,k,n=0;
    cin>>T;
    for(int t=0;t<T;t++){
        priority_queue<int,vector<int>,greater<int>> lpq;
        priority_queue<int> gpq;
        map<int,int> nums;
        cin>>k;
        char c;
        for(int i=0;i<k;i++){
            cin>>c>>n;
            if(c=='I'){
                nums[n]++;
                lpq.push(n);
                gpq.push(n);
            }else{
                if(n==1){
                    while(!gpq.empty()&&nums[gpq.top()]==0) gpq.pop();
                    if(!gpq.empty()){
                        nums[gpq.top()]--;
                        gpq.pop();
                    }
                }    
                else{
                    while(!lpq.empty()&&nums[lpq.top()]==0) lpq.pop();
                    if(!lpq.empty()){
                        nums[lpq.top()]--;
                        lpq.pop();
                    }
                }
            }
        }
        while(!gpq.empty()&&nums[gpq.top()]==0) gpq.pop();
        while(!lpq.empty()&&nums[lpq.top()]==0) lpq.pop();

        if(gpq.empty()||lpq.empty()) cout<<"EMPTY\n";
        else cout<<gpq.top()<<' '<<lpq.top()<<'\n';

        
    }
    return 0;
}