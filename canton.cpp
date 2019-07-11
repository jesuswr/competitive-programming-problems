#include <iostream>

int main(){
    int n,m,aux,aux2;
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&m);

        aux2 = 1;
        aux = 0;

        while (aux2*(aux2+1)/2<m){
            aux2++;
        }

        aux = m - aux2*(aux2-1)/2;

        aux2= aux2 - aux +1;
        

        if ( (aux2+aux)%2==0){
            printf("TERM %d IS %d/%d\n",m,aux2,aux);
        }
        else{
            printf("TERM %d IS %d/%d\n",m,aux,aux2);
        }

    }
    
}