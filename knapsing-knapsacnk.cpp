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
const ll LLINF = (2<<18) + 18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll arr[LLINF];
queue<pair<ll,ll>> q;
map< ll , ll > ind;  // aqui van cuanto individuales hay
unordered_map< ll , ll > enc;	// aqui van cuantos hemos encontrado
unordered_map< ll , ll > cre;		// aqui van cuantos hay total


int main()
{
	int n;
	ri(n);
	ll m = 1<<n;
	FOR(i,0,m)
	{
		rl(arr[i]);
	}
	sort( arr , arr + m);
	ll contador = 0;
	if ( arr[0] != 0 )
	{
		printf("impossible\n");
		return 0;
	}
	if ( n == 1 )
	{
		printf("%lld\n", arr[1]);
	}
	else
	{
		FOR(i,1,m)
		{
			if ( contador > n)
			{
				printf("impossible\n");
				return 0;
			}
			if ( enc.find( arr[i] ) == enc.end() ) enc[arr[i]] = 1;
			else enc[arr[i]]++;

			if ( cre.find( arr[i] ) == cre.end() || cre[arr[i]] < enc[arr[i]] )
			{	

				for( auto p : cre )
				{
					q.push(p);
				}
				contador++;
				if ( ind.find(arr[i]) == ind.end()) ind[arr[i]] = 1;
				else ind[arr[i]]++;
				if ( cre.find(arr[i]) == cre.end()) cre[arr[i]] = 1;
				else cre[arr[i]]++;
				while( !q.empty() )
				{
					if ( cre.find(arr[i]+ q.front().first) == cre.end()) cre[arr[i] + q.front().first] = q.front().second;
					else cre[arr[i]+ q.front().first] += q.front().second;
					q.pop();
				}
			}
		}
		
			
		
		if ( contador == n )
		{
			for ( auto p : ind )
			{
				FOR(i,0,p.second) printf("%lld\n", p.first);
			}
		}
		else
		{
			printf("impossible\n");
		}
	}	
	
	return 0;
}