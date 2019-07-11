#include <iostream>

using namespace std;



int main(){
	int n;
	scanf("%d",&n);
	int c1=0, c2=0, n1=0, n2=0, aux=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&aux);
		if (c1 == 0){
			c1 = aux;
			n1 ++;
		}
		else if (c1==aux) n1 ++;
		else if (c2 == 0) {
			c2 = aux;
			n2++;
		}
		else if (c2==aux) n2 ++;
		else{
			aux = -1;
			break;
		}
	}

	if (aux==-1 || n1!=n2) printf("NO\n");
	else printf("YES\n%d %d\n",c1,c2);
	
}