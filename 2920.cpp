#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> input(8);
    bool asc=true,des=true;
    for(int i=0;i<8;i++){
        cin>>input[i];
        if(input[i]!=i+1){
            asc=false;
        }
        if(input[i]!=8-i){
            des=false;
        }
    }
    if(asc){
        cout<<"ascending";
    }else if(des){
        cout<<"descending";
    }else{
        cout<<"mixed";
    }

}