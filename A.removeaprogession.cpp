#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int n , x;
	while(t--) {
	    scanf("%d %d", &n, &x);
	    x = 2*x;
	    printf("%d\n", x);
	}
}
