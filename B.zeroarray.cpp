#include <iostream>
#include <algorithm>
#include <queue>



using namespace std;

long long numbs[int(1e5)+5];

int main(){
	int n;
	scanf("%d", &n);
	long long aux = 0;
	long long aux2 = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &numbs[i]);
		aux += numbs[i];
		aux2 = max( aux2, numbs[i] );
	}
	if (aux%2==0 && aux2<=aux-aux2)
	{
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}
