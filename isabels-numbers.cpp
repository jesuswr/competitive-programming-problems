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

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
ll arr[200];

ll f ( int x )
{
	if ( arr[x] != -1 ) return arr[x];
	arr[x] = 10*f(x-7) + 8;
	return arr[x];
}

int main()
{
	int t;
	ri(t);
	for (int i = 0; i <= 128; ++i)
	{
		arr[i] = -1;
	}
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 2;
	arr[4] = 2;
	arr[5] = 6;
	arr[6] = 8;
	arr[7] = 10;
	arr[8] = 18;
	arr[9] = 20;
	arr[10] = 20;
	arr[11] = 28;
	arr[12] = 68;
	arr[13] = 88;
	arr[14] = 108;
	arr[15] = 188;
	arr[16] = 200;
	arr[17] = 208;
	arr[18] = 288;
	arr[19] = 688;
	arr[20] = 888;
	arr[21] = 1088;
	while(t--)
	{
		ri(n);
		ll ans = f(n);
		printf("%lld\n", ans);

	}
	return 0;
}