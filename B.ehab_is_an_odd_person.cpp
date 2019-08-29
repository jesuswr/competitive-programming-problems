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
#include <unordered_map>


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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int arr[maxN + 5];


int main()
{
	int n;
	ri(n);
	bool odd = false;
	bool even = false;
	for (int i = 0; i < n; ++i)
	{
		ri(arr[i]);
		if ( arr[i] % 2 == 0) even = true;
		else odd = true;
	}

	if ( even && odd) sort(arr,arr+n);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i] );
	}
	printf("\n");
	return 0;
}