#include <iostream>

using namespace std;

int main()
{
	int n,m;
	scanf("%d %d", &n, &m);
	if (m==0) {printf("No\n");return 0;}
	if (n==0 && m==0) {printf("No\n");return 0;}
	m--;
	if (m==0 && n>0) {printf("No\n");return 0;}
	if (m==0 && n==0) {printf("Yes\n");return 0;}
	if (n-m<0) {printf("No\n");return 0;}
	if ((m-n)%2==0) {printf("Yes\n");return 0;}
	printf("No\n");
}
