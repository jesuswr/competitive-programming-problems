#include <iostream>

int stuPref[20][20];
int n;
unsigned long long int count;
int assign[20];

void getCount(int stud){
    if (stud==n){
        count ++;
    }
    else{

        for(int i = 0; i < n; i++)
        {
            if (stuPref[stud][i]==1 && assign[i]==0){
                assign[i] = 1;
                getCount(stud+1);
                assign[i] = 0;
            }
        }
        

    }
}







int main(){
    int c;
    scanf("%d",&c);
    
    
    

    for(int ii = 0; ii < c; ii++)
    {
        scanf("%d",&n);

        count = 0;

        for(int i = 0; i < n; i++)
        {
            for (int j=0; j<n; j++)
            {
                scanf("%d",&stuPref[i][j]);
            }
            assign[i] = 0;
        }
        
    

    getCount(0);

    printf("%llu\n",count);  
     
    int nose = 0;
    nose = (nose | (1 << nose));
    std::cout << nose <<"\n";
    }
}