#include <iostream>
#include <math.h> 

int main(){
    int n;
    int a,b;
    int unMedio=0,tresCuartos=0,unCuarto=0;
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
    {
       scanf("%d/%d",&a,&b);
       if (b==2){
           unMedio++;
       }
       else if (a==1 && b==4){
           unCuarto++;
       }
       else{
           tresCuartos++;
       }
    }

    n=1;
    
    if (tresCuartos>=unCuarto){
        n=n+tresCuartos;
        n = n + unMedio/2;
        if (unMedio%2!=0){
            n++;
        }
    }
    else{
        n = n + tresCuartos;
        unCuarto = unCuarto - tresCuartos;
        n = n + unMedio/2;
        if (unMedio%2!=0){
            n++;
            unCuarto = unCuarto - 2;
        }
        if (unCuarto>0){
            n = n + unCuarto/4;
            if  (unCuarto%4!=0){
                n++;
            }
        }

    }
    
    
    printf("%d",n);
}