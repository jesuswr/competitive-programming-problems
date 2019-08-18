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
	ll n, m, q;
	rll(n,m);
	long long mcd = __gcd(n,m);
	long long z1, z2;
	z1 = n/mcd;
	z2 = m/mcd;
	rl(q);
	ll x1, y1, x2, y2;
	while(q--) 
	{
	   rll(x1,y1);
	   rll(x2,y2);
	   ll ans1, ans2;
	   if (x1==1)
	   {
	   		ans1 = y1/z1;
	   		if (y1%z1==0) ans1--;
	   }
	   else
	   {
	   		ans1 = y1/z2;
	   		if (y1%z2==0) ans1--;
	   }
	   if (x2==1)
	   {
	   		ans2 = y2/z1;
	   		if (y2%z1==0) ans2--;
	   }
	   else
	   {
	   		ans2 = y2/z2;
	   		if (y2%z2==0) ans2--;
	   }


	   ans1 == ans2 ? printf("YES\n"): printf("NO\n");

	}

	return 0;
}