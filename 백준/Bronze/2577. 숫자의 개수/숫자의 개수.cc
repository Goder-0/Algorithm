#include <iostream>

using namespace std;

int arr[10];
int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int num = A*B*C;
    while(num!=0){
	    arr[num%10]++;
	    num/=10;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<'\n';
    }
}