#include <iostream>

using namespace std;

int n;

int main(){
	scanf("%d",&n);
	
	int aux;
	int sum;
	sum = 1;
	while(sum %4 !=0) {
		sum = 0;
		aux = n;
		sum += aux%10;
		aux = aux/10;
		if (aux>0){
			sum += aux%10;
			aux = aux/10;
		}
	
		if (aux>0){
			sum += aux%10;
			aux = aux/10;
		}
		if (aux>0){
			sum += aux%10;
		}
		n++;
		
	
	}
	n = n-1;
	
	
	printf("%d\n",n);
}
