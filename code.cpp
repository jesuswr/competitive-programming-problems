#include <iostream>

int main(){
    
    int x,y,n;
    int ans;
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
    scanf("%d",&x);
    scanf("%d",&y);


    if ( x==y || x==(y+2)){
        if ( x==y && x%2==0){
            ans = 2*y;
        }
        else if (x==y && x%2==1){
            ans = 2*y - 1;
        }
        else if ( x!=y && x%2==0 ){
            ans = (x-1)*2;
        }
        else if ( x!=y && x%2==1 ){
            ans = y+x-1;
        }

        printf("%d\n",ans);
    }
    else{
        printf("No Number\n");
    }
    }
}
