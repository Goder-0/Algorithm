#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define io ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    io;
    int T,N,M;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N>>M;
        int v,count=0;
        queue<int> doc;
        vector<int> seq(N);
        for(int i=0;i<N;i++){
            cin>>v;
            doc.push(v);
            seq[i]=v;
        }
        sort(seq.begin(),seq.end(),greater<int>());
        int i=0;
        while(i<N){
            if(seq[i]==doc.front()){
                count++;
                if(M==0) break;
                doc.pop();
                i++;
            }else{
                int temp=doc.front();
                doc.pop();
                doc.push(temp);
            }
            if(M>0) M--;
            else if(M==0) M=doc.size()-1;
        }
        cout<<count<<'\n';
        
    }
    return 0;
}