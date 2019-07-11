#include <iostream>

int space, items;
int itemSpaces[2001], itemValues[2001];
int bestValuePerSize[2001][2001];


int getValue(int index, int space){

    if (bestValuePerSize[index][space]!=-1){
        
        return bestValuePerSize[index][space];
    }
    else{
        if (index == 0 || space ==0){
            bestValuePerSize[index][space]=0;
        }
        else if(itemSpaces[index]>space){
            bestValuePerSize[index][space] = getValue(index-1,space);
        }
        else
        {
            bestValuePerSize[index][space] = std::max(getValue(index-1,space),
                                            getValue(index-1,space-itemSpaces[index])+itemValues[index] );
            
        }
        
        return bestValuePerSize[index][space];
    }
    

}

int main(){
    scanf("%d %d",&space,&items); 

    for(int i = 1; i <= items; i++)
    {
        scanf("%d %d",&itemSpaces[i],&itemValues[i]);
    }
    
    for(int i = 0; i <= items; i++)
    {
        for (int j = 0; j<=space; j++){
            bestValuePerSize[i][j]=-1;
        }
    }
    
    int ans = getValue(items,space);

    printf("%d\n",ans);
    
}