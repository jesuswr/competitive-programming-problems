#include <iostream>
#include <algorithm>

int secondSmallest(int positions[], int n){
    int smaller = std::min(positions[0],positions[1]);
    int secondSmaller = std::max(positions[0],positions[1]);

    for(int i = 2; i < n; i++)
    {
        if (positions[i]<smaller){
            secondSmaller = smaller;
            smaller = positions[i];
        }
        else if (positions[i]<secondSmaller){
            secondSmaller = positions[i];
        }
    }
    
    return secondSmaller;
}

int smallest(int positions[], int n){
    int ans = positions[0];
    for(int i = 1; i < n; i++)
    {
        if (positions[i]<ans){
            ans = positions[i];
        }
    }
    return ans;
    
}

int main(){
    int a;
    int d;
    int secondMinimun;
    int min;

    scanf("%d",&a);
    scanf("%d",&d);

    while(a!=0 && d!=0){        

        int defenders[d];
        int atackers[a];

        for(int i = 0; i < a; i++)
        {
            scanf("%d",&atackers[i]);
        }

        for(int i = 0; i < d; i++)
        {
            scanf("%d",&defenders[i]);
        }

        min = smallest(atackers,a);
        secondMinimun = secondSmallest(defenders,d);

        if (min<secondMinimun) {
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
        
        scanf("%u",&a);
        scanf("%u",&d);
        
    }

}

