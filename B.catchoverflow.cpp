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
const ll maxN = 4294967300; // CAMBIAR ESTE

// GJNM
char s[10];

int main()
{
	int l;
	ri(l);
	ll ops = 0;
	
	ll aux;
	vector<ll> nose;
	for (int i = 0; i < l; ++i)
	{
		if ( ops > 4294967295 ) {printf("OVERFLOW!!!\n"); return 0;}
		scanf("%s",s);
		if (s[0] == 'f')
		{
			rl(aux);
			if ( nose.size() > 0) aux = aux*nose[nose.size()-1];
			nose.push_back(min(maxN,aux));
		}
		else if ( s[0] == 'e')
		{
			nose.pop_back();
		}
		else
		{
			if ( nose.size() > 0) ops += nose[nose.size()-1];
			else ops++;
		}


	}
	if ( ops > 4294967295 ) printf("OVERFLOW!!!\n");
	else printf("%lld\n", ops);
	return 0;
}