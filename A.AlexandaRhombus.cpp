#include <iostream>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	long long ans = 2*n*n - 2*n+1;
	printf("%lld\n", ans);
}
