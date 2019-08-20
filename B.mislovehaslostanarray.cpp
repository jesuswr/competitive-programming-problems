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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
// no me hackeen

int main()
{
	int n, l, r;
	riii(n,l,r);
	long long min = 1;
	int last = 1;
	int elements = 1;
	for (int i = 1; i < n; ++i)
	{
		if ( elements < l) 
		{
			elements++;
			last = last*2;
			min += last;
		}
		else
		{
			min += 1;
		}
	}
	last = 1;
	elements = 1;
	long long max = 1;
	for (int i = 1; i < n; ++i)
	{
		if ( elements < r) 
		{
			elements++;
			last = last*2;
			max += last;
		}
		else
		{
			max += last;
		}
	}
	printf("%lld %lld\n", min,max);
	return 0;
}