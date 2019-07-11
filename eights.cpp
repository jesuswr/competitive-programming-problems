#include <iostream>

int main(){
    int n;
    long long ans,m;
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&m);
        ans=192 + 250*(m-1);
        printf("%lld\n",ans);


    }
    
}