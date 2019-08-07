#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long d;
	long long pos[3];
	scanf("%lld %lld %lld %lld", &pos[0], &pos[1], &pos[2], &d);
	sort(pos, pos+3);
	long long ans = 2*d - (min(pos[2]-pos[1],d)) - (min(pos[1]-pos[0],d));
	printf("%lld\n", ans);
}
