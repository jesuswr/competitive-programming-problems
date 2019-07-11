#include <iostream>

int main(){
    int n;
    float cont;
    float m;

    scanf("%f",&m);

    while(m){

        n = 0;
        cont = 0.0;

        while(m>cont){
            n++;
            cont = cont + 1.0/(n+1.0);
        }

        printf("%d card(s)\n",n);
        scanf("%f",&m);

    }
}