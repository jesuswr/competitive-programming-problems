#include <iostream>

using namespace std;

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	if ( min(m,k) >= n ) printf("Yes\n");
	else printf("No\n");
	return 0;
}
