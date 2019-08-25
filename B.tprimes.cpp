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
unordered_map<ll,bool> mp;

bool checkPrime ( ll x )
{
	for (ll i = 2; i*i <= x; ++i)
	{
		if ( x % i == 0) return false;
	}

	return true;
}


int main()
{
	int n;
	ri(n);
	ll aux;
	for (ll i = 2; i <= 1e6; ++i)
	{
		if ( checkPrime(i) ) mp[(ll)i*i] = true;
	}
	for (int i = 0; i < n; ++i)
	{
		rl(aux);
		if ( mp.find(aux) == mp.end()) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}