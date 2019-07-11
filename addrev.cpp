#include <iostream>

int reverse(int n){
    int revNumb = 0;
    
    while(n>0){
        revNumb = revNumb*10 + n%10;
        n = n/10;
    }
    return revNumb;

}


int main(){
    int n,a,b,c,d;
    scanf("%d",&n);
    

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        
        c= reverse(a);
        d=reverse(b);
        

        a= c + d;
        a = reverse(a);
        printf("%d\n",a);
    }
    

}