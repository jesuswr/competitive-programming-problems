#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
int arr[2*maxN];

int main()
{
	int n;
	ri(n);
	if (n%2==0) {printf("NO\n");return 0;}
	int start, mid;
	start = 0;
	mid = n;
	int max = 2*n;
	int min = 1;
	for (int i = 0; i < n; ++i)
	{
		if ( i%2 == 0)
		{
			arr[start] = min;
			min++;
			arr[mid] = min;
			min++;
			start++;
			mid++;
		}
		else
		{
			arr[start] = max;
			max--;
			arr[mid] = max;
			max--;
			mid++;
			start++;
		}
	}
	bool ans = true;
	printf("YES\n");
	for (int i = 0; i < 2*n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}