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
const int maxN = 11; // CAMBIAR ESTE

int n;
bool visited[2<<11];
int ages[maxN];

bool lookfordigits( int bit, int ag)
{
	if ( ag < 0) return false;
	int aux = ag;
	int digit;
	int aux2 = bit;
	while ( aux > 0)
	{
		digit = aux % 10; aux = aux / 10;
		if ( aux2 & ( 1 << digit ) )
		{
			aux2 -= ( 1 << digit );
			continue;
		}
		else return false;
	}
	return true;
}

bool sol( int btm, int age)
{
	if ( lookfordigits( btm, age ) ) return true;
	int used = 0;
	for (int i = 1; i < 10; ++i)
	{
		if ( btm & ( 1 << i ) )
		{
			if ( age > i && lookfordigits( btm - ( 1 << i) , age - i ) ) return true; 
		
			for (int j = 1; j < 10 && age > 10; ++j)
			{
				if ( i != j && ( btm & ( 1 << j ) ) )
				{
					if ( 10*i+j < age - 10 && lookfordigits( btm - ( 1 << i ) - ( 1 << j ) , age - 10*i-j) ) return true;
					
				}
			}
		}
		
	}
	return false;
}

bool checkSol( int bitm )
{
	bool ans = true;
	for (int i = 0; i < n; ++i)
	{
		if ( !ans ) break;
		ans &= sol( bitm, ages[i] );
	}
	return ans;
}

int main()
{
	n=1;
	int t = 0;

	while (n) 
	{
		t++;
		ri(n);
		if (n==0) break;
		for (int i = 0; i < n; i++ )
		{
			ri(ages[i]);
		}
		for (int i = 0; i < ( 1 << 11 ); ++i)
		{
			visited[i] = false;
		}
		queue<pii> q;
		int ans = INF;
		int p = INF;
		q.push({0,0});
		visited[0] = true;
		int l;
		int bm;
		while( !q.empty() ) 
		{
		   	bm = q.front().first;
		   	l = q.front().second;
		   	q.pop();
		   	
		   	if ( l > p) break;
		   	if ( checkSol(bm) ) 
		   	{
		   		p = l;
		   		ans = min(ans,bm);
		   	}
		   	if ( p != INF) continue;

		   	for (int i = 0; i < 10; ++i)
		   	{
		   		if ( bm & ( 1 << i ) ) continue;
		   		if ( !visited[ bm | ( 1 << i ) ]) 
				{
					visited[ bm | ( 1 << i ) ] = true;
					q.push( { bm | ( 1 << i ) , l + 1} );	
				}
		   	}
		}

		while(!q.empty()) q.pop();
		

		printf("Case %d: ", t);
		for (int i = 9; i >= 0; --i)
		{
			if ( ans & ( 1 << i) ) printf("%d", i);
		}
		printf("\n");
	}
}