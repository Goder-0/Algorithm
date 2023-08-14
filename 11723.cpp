#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    set<int> nums;
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        string s;
        int x;
        cin>>s;
        if(s=="add"){
            cin>>x;
            if(nums.count(x)==0) nums.insert(x);
        }else if(s=="check"){
            cin>>x;
            cout<<nums.count(x)<<'\n';
        }else if(s=="remove"){
            cin>>x;
            if(nums.count(x)==1) nums.erase(x);
        }else if(s=="toggle"){
            cin>>x;
            if(nums.count(x)==1) nums.erase(x);
            else nums.insert(x);
        }else if(s=="all"){
            nums={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        }else if(s=="empty"){
            nums.clear();
        }
    }
    return 0;
}