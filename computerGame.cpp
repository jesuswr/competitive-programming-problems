#include <iostream>

using namespace std;

long long int n, k, a, b;

int main(){

	int q;
	scanf("%d",&q);
	long long int n1,n2;

	for (int kk = 0; kk < q; kk++)
	{
		scanf("%lld %lld %lld %lld",&k,&n,&a,&b);
		//printf("%d %d %d %d\n",n,k,a,b );

		n1 = b*n;

		if (n1>=k)
		{
			printf("-1\n");
		}
		else{
			k = k - n1;
			n2 = a -b;
			if (k%n2==0){
				k = k -1;
			}
			n1 = k/n2;
			n1 = min(n1,n);
			printf("%lld\n", n1);
		}		
	}

}