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
#define rlll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c);

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e13;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
char str[102];
ll  B, S, C;
ll 	PB, PS, PC;
ll 	CB, CS, CC;
ll 	money;

bool valid ( ll val )
{
	ll zero = 0;
	ll neededB = CB*val - B;
	//printf("%lld %lld\n", val, neededB);
	ll neededS = CS*val - S;
	ll neededC = CC*val - C;
	return max(neededB*PB,zero) + max(neededS*PS,zero) + max(neededC*PC,zero) <= money;
}

int main()
{
	scanf("%s",str);
	rlll( B , S , C );
	rlll( PB , PS , PC );
	rl( money );
	CB = CS = CC = 0;
	for (int i = 0; i < strlen(str); ++i)
	{
		if ( str[i] == 'B') CB++;
		else if ( str[i] == 'S') CS++;
		else CC++;
	}
	//printf("%lld %lld %lld\n", B, PB, CB);
	//printf("%lld %lld %lld\n", S, PS, CS);
	//printf("%lld %lld %lld\n", C, PC, CC);
	ll s = 0;
	ll e = 1e13;
	ll ans ;
	while ( s <= e )
	{
		ll m = ( s + e ) / 2;
		//printf("%lld\n",m );
		if ( valid( m ) )
		{
			ans = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	printf("%lld\n", ans);
	return 0;
}