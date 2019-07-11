#include <iostream>

int main() {

    int a,b,c,ans;
    scanf("%d %d %d",&a,&b,&c);
    
    while (!(a==0 && b==0 && c==0)){
        
        if ( (b-a)==(c-b) ){
            ans = c + b - a;
            printf("AP %d\n",ans);
        }
        else{
            ans = c * (b/a);
            printf("GP %d\n",ans);

        }

        scanf("%d %d %d",&a,&b,&c);

    }
    
    return 0;
}