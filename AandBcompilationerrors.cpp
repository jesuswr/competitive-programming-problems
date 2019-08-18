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



int main()
{
	int n;
	ri (n);
	long long aux;
	long long sum1 = 0;
	for (int i = 0; i < n; ++i)
	{
		rl(aux);
		sum1 += aux;
	}
	long long sum2 = 0;
	for (int i = 0; i < n-1; ++i)
	{
		rl(aux);
		sum2 += aux;
	}
	long long sum3 = 0;
	for (int i = 0; i < n-2; ++i)
	{
		rl(aux);
		sum3 += aux;
	}
	printf("%lld\n", sum1-sum2);
	printf("%lld\n", sum2-sum3);
	return 0;
}