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
const int maxN = 100; // CAMBIAR ESTE

int arr[maxN];
vi abc;
vi def;

int findNum(vi v, int num)
{
	int start, end, mid, mn, mx;

	start = 0;
	end = v.size() - 1;
	mn = INF;
	while ( start <= end )
	{
		mid = ( ( start + end ) / 2);
		if ( v[mid] == num )
		{
			mn = min( mn, mid);
			end = mid - 1;
		}
		else if ( v[mid] < num )
		{
			start = mid + 1;
		}
		else 
		{
			end = mid - 1;
		}
	}
	if ( mn == INF ) return -1;
	start = 0;
	end = v.size() - 1;
	mx = -1;
	while ( start <= end )
	{
		mid = ( ( start + end ) / 2);
		if ( v[mid] == num )
		{
			mx = max( mx, mid);
			start = mid + 1;
		}
		else if ( v[mid] < num )
		{
			start = mid + 1;
		}
		else 
		{
			end = mid - 1;
		}
	}
	return (mx-mn+1);
}


int main()
{
	int n;
	ri(n);
	if (n==0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		ri(arr[i]);
	}

	
	int aux;
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			for (int j = 0; j < n; ++j)
			{
				aux = arr[i]*arr[k] + arr[j];
				abc.push_back(aux);
				if ( arr[j] == 0) continue;
				aux = ( arr[i] + arr[k] ) * arr[j];
				def.push_back(aux);
			}
		}
	}

	sort( abc.begin(), abc.end() );
	sort( def.begin(), def.end() );
	
	int a, b;
	ll ans = 0;

	for ( auto it = abc.begin(); it < abc.end(); it++)
	{
		a = ( upper_bound( abc.begin(), abc.end(), *it ) - lower_bound( abc.begin(), abc.end(), *it ) );
		b = ( upper_bound( def.begin(), def.end(), *it ) - lower_bound( def.begin(), def.end(), *it ) );
		
		ans += a*b;
		it += a - 1;
		
	}
	
	
	printf("%lld\n", ans);
}