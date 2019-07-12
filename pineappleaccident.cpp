#include <iostream>


int main()
{
	int t, s, c;
	scanf("%d %d %d", &t, &s, &c);
	c = c - t;
	if (c<0) {printf("NO\n"); return 0;}
	if (c==0) {printf("YES\n"); return 0;}
	if ((c%s==0 || c%s==1) && c>=s) {printf("YES\n"); return 0;}
	printf("NO\n");
}