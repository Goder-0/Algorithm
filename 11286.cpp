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
    int N;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    map<int,int> nums;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(x==0){
            if(min_heap.empty())cout<<"0\n";
            else {
                if(nums[min_heap.top()*-1]>0){
                    cout<<min_heap.top()*-1<<'\n';
                    nums[min_heap.top()*-1]--;
                }
                else {
                    cout<<min_heap.top()<<'\n';
                    nums[min_heap.top()]--;
                }
                min_heap.pop();
            }
        }else {
            nums[x]++;
            if(x<0) x*=-1;
            min_heap.push(x);
        }
    }
    return 0;
}