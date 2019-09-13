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

struct node
{
	int f, s, t;
};

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

bool check( piii x)
{
	return __gcd(x.first,__gcd(x.second.first,x.second.second)) != 1;
}


void bfs( int a , int b , int c )
{
	queue<piii> q;
	map<piii,bool> mp;
	q.push({a,{b,c}});
	mp[{a,{b,c}}] = true;
	int teams = -1;
	int moves = INF;
	bool add = true;

	while ( !q.empty() )
	{
		piii x = q.front();
		//printf("%d %d %d\n", x.first, x.second.first, x.second.second);
		q.pop();
		if ( check(x) )
		{
			if ( x.first - a + x.second.first - b + x.second.second - c <= moves)
			{

				moves = x.first - a + x.second.first - b + x.second.second - c;
				teams = max( teams, __gcd(x.first,__gcd(x.second.first,x.second.second)) );
				add = false;
			}
		}
		if ( add )
		{
			if ( mp.find( {x.first+1,{x.second.first,x.second.second}} ) == mp.end())
			{
				//printf("hola1\n");
				mp[{x.first+1,{x.second.first,x.second.second}}] = true;
				q.push({x.first+1,{x.second.first,x.second.second}});
			}
			if ( mp.find( {x.first,{x.second.first+1,x.second.second}} ) == mp.end())
			{
				//printf("hola2\n");
				mp[{x.first,{x.second.first+1,x.second.second}}] = true;
				q.push({x.first,{x.second.first+1,x.second.second}});
			}
			if ( mp.find( {x.first,{x.second.first,x.second.second+1}} ) == mp.end())
			{
				//printf("hola3\n");
				mp[{x.first,{x.second.first,x.second.second+1}}] = true;
				q.push({x.first,{x.second.first,x.second.second+1}});
			}
		}
	}
	printf("%d %d \n", teams, moves);

}

// GJNM

int main()
{
	while ( true )
	{
		int a , b , c;
		riii(a,b,c);
		if ( a == 0 && b == 0 && c == 0 ) break;
		bfs(a,b,c);
	}
	return 0;
}