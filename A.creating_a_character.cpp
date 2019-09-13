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
ll str, inte, expe;


bool valid( ll x )
{
	return x + inte < str + expe - x;
}


int main()
{
	int t;
	ri(t);
	while (t--)
	{
		rll(str,inte);
		rl(expe);
		ll s = 0, e = expe, m, ans=0;
		while ( s <= e )
		{
			m = (s+e)/2;
			//printf("entro con %lld\n", m);
			if (valid(m))
			{
				//printf("con %lld dio true\n", m);
				ans = m+1;
				s = m+1;
			}
			else 
			{
				e = m - 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}