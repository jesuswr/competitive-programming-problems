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

char num[101];

int main()
{
	scanf("%s", num);
	int ones = 0;
	for (int i = 0; i < strlen(num); ++i)
	{
		if ( num[i] == '1' ) ones++;
	}
	if ( strlen(num) == 1) 
	{
		printf("0\n");
		return 0;
	}
	int l = strlen(num) - 2;
	int ans = 1;
	ans += l/2;
	if (l%2!=0 && ones>1) ans++;
	printf("%d\n", ans);
	return 0;
}