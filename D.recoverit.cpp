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
const int maxN = 4e5; // CAMBIAR ESTE

// GJNM
bool primes[2750131];
ll P[maxN+2];
vector<ll> primos;
vector<ll> noprimos;
ll prime[maxN+2];
unordered_map<long long, int> notused;



bool checkPrime2(ll x)
{
	for (ll i = 2; i*i <= x; ++i)
	{
		if ( x%i == 0) return false;
	}
	return true;
}

ll maxDiv( ll x )
{
	if ( x % 2 == 0) return x/2;
	for (ll i = 3; i < x; i = i + 2)
	{
		if ( x%i == 0 ) return x/i;
	}
}

void nose()
{
	P[1] = 2;
	primes[2] = true;
	primes[1] = true;
	ll aux = 3;
	for (ll i = 2; i <= 199999; ++i)
	{
		while( !checkPrime2(aux) ) 
		{
			primes[aux] = false;
		    aux++;
		}
		primes[aux] = true;
		P[i] = aux;
		aux++;
	}
}

int main()
{
	int n;
	ri(n);
	ll aux;
	nose();
	for (int i = 0; i < 2*n; ++i)
	{
		rl(aux);
		if ( notused.find(aux) == notused.end()) notused[aux] = 0;
		notused[aux] ++;
		if ( primes[aux] )
		{	
			primos.push_back(aux);
		}
		else
		{
			noprimos.push_back(aux);
		}
	}

	sort(noprimos.begin(),noprimos.end(),greater<ll>());
	queue<ll> q;

	for (int i = 0; i < noprimos.size(); ++i)
	{

		ll md = maxDiv( noprimos[i] );
		if ( notused[ noprimos[i] ] == 0 || notused[md] == 0) continue;

		q.push( noprimos[i] );
		notused[noprimos[i]] --;
		notused[md] --;

	}

	sort(primos.begin(),primos.end());

	for (int i = 0; i < primos.size(); ++i)
	{
		if ( q.size() == n) break;
		if ( notused[ primos[i] ] == 0 ) continue;
		notused[primos[i]]--;
		notused[P[primos[i]]]--;
		q.push(primos[i]);
		
	}

	while(!q.empty()) 
	{
	    printf("%lld ", q.front());
	    q.pop();
	}
	printf("\n");
	
	return 0;
}