#include <iostream>
#include <vector>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

bool compare(string a, string b){
    if(a.length()==b.length()){
        return a<b;
    }else{
        return a.length()<b.length();
    }     
}

int main(){
    io;
    int N;
    cin>>N;
    string temp;
    vector<string> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),compare);
    cout<<arr[0]<<'\n';
    for(int i=1;i<N;i++) if(arr[i]!=arr[i-1])cout<<arr[i]<<'\n';
}