#include <iostream>

int main(){
    int serie[100001];
    int n;
    int j;
    int cond;
    scanf("%d",&n);
    while(n){

        for(int i = 1; i < n+1; i++)
        {
            scanf("%d",&serie[i]);
        }
        j=1;
        cond=1;

        while(j<n+1 && cond){
            if (serie[serie[j]]==j){
                j++;
            }
            else
            {
                cond = 0;
            }
            
        }

        if (cond==1) {
            printf("ambiguous\n");

        }
        else
        {
            printf("not ambiguous\n");
        }
        
        






        scanf("%d",&n);
    }

}