#include <iostream>

int c,n,neededOxy,neededNit;
int oxy[1001],nit[1001],weight[1001];
int minWei[22][80][1001];
int ans;
// :(
int getMin(int o, int n, int index){
    if (minWei[o][n][index]!=-1){
        return minWei[o][n][index];
    }
    else{
        if (o==0 && n==0){
            minWei[o][n][index] = 0;
        }
        else if (index==0){
            
            minWei[o][n][index] = 999999999;
        }
        else{
            minWei[o][n][index] = std::min(getMin(o,n,index-1),
                                    getMin(std::max(o-oxy[index],0),
                                    std::max(n-nit[index],0),index-1)+weight[index]);
        }
        return minWei[o][n][index];

    }

}






int main(){
    scanf("%d",&c);

    for(int h = 0; h < c; h++)
    {
        scanf("%d %d",&neededOxy,&neededNit);
        scanf("%d",&n);

        for(int i = 0; i <= neededOxy; i++)
        {
            for (int j = 0; j<=neededNit;j++){
                for(int k = 0; k <= n; k++)
                {
                    minWei[i][j][k]=-1;     
                }
            }
        }

        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d %d",&oxy[i],&nit[i],&weight[i]);
        }

        ans = getMin(neededOxy,neededNit,n);
        printf("%d\n",ans);
    }

    
    

    
}