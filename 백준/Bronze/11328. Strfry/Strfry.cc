//54분
#include <bits/stdc++.h>
#define IM "Impossible"
#define P "Possible"

using namespace std;

int arr[26];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        fill(arr,arr+26,0);
        string a,b;
        cin>>a>>b;
        for(char c:a){
            arr[c-'a']++;
        }
        for(char c:b){
            arr[c-'a']--;
        }
        bool res=true;
        for(int i :arr){
            if(i!=0) {
                res=false;
                break;
            }
        }
        if(res) cout<<P;
        else cout<<IM;
        if(i!=N-1) cout<<'\n';
    }
}