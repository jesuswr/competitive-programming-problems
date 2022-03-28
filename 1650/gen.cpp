#include<iostream>
using namespace std;

int main(){
    cout<<1<<endl<<endl;
    cout<<150001<<" "<<200000<<endl;
    cout<<1<<" "<<149998<<endl;
    for(int i=1;i<=2e5;i++){
        if(i%4==1){
            cout<<i-i/4<<" "<<i-i/4+1<<endl;
        }else if(i%4==2){
            cout<<i-i/4-1<<" "<<i-i/4+1<<endl;
        }else if(i%4==3){
            cout<<i-i/4-1<<" "<<i-i/4+1<<endl;
        }else{
            cout<<i-i/4<<" "<<i-i/4+1<<endl;
        }
    }
    return 0;
}
