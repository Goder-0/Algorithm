#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
vector<bool> nums(10,true);
int res=INT_MAX;
int N,M;

void selectNum(string num){
    for(int i=0;i<10;i++){
        if(nums[i]){
            num+=to_string(i);
            res=min(res,abs(N-stoi(num))+(int)num.length());
            if(num.length()<6) selectNum(num);
            num.pop_back();
        }
    }
}


int main()
{
    io;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int n;
        cin>>n;
        nums[n]=false;
    }
    res=abs(N-100);
    selectNum("");
    cout<<res;
    return 0;
}