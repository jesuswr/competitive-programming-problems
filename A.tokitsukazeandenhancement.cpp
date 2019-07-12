#include <iostream>

int main()
{
	int x; 
	scanf("%d",&x);

	if (x%4==1) printf("0 A\n");
	if (x%4==3) printf("2 A\n");
	if (x%4==2) printf("1 B\n");
	if (x%4==0) printf("1 A\n");
}