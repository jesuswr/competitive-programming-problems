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
const int maxN = 3e5 + 5; // CAMBIAR ESTE
const ll MOD = 998244353;

// GJNM
pii arr[maxN];
ll fact[maxN];

int main()
{
	int n;
	ri(n);
	fact[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		rii(arr[i].first,arr[i].second);
		fact[i+1] = (fact[i]*(i+1) )%MOD;
	}

	sort(arr,arr+n);
	ll cont1 = 1;
	for (int i = 0; i < n; ++i)
	{
		int j = i;
		ll count = 0;
		while( j < n && arr[j].first == arr[i].first) 
		{
		    j++;
		    count++;
		}
		cont1 = ( cont1 * fact[count] )%MOD;
		i = j-1;
	}
	int w;
	for (int i = 0; i < n; ++i)
	{
		w = arr[i].first;
		arr[i].first = arr[i].second;
		arr[i].second = w;
	}
	sort(arr,arr+n);
	ll cont2 = 1;
	for (int i = 0; i < n; ++i)
	{
		int j = i;
		ll count = 0;
		while( j < n && arr[j].first == arr[i].first) 
		{
		    j++;
		    count++;
		}
		cont2 = ( cont2 * fact[count] )%MOD;
		i = j -1;
	}
	map<pii, int> mp;
	ll cont12 = 1;
	for (int i = 0; i < n-1; ++i)
	{
		if ( arr[i].second > arr[i+1].second ) { cont12 = 0; break; }
	}

	if ( cont12 )
	{
		for (int i = 0; i < n; ++i)
		{
			mp[arr[i]]++;
		}
		for (pair<pii,int> p : mp) cont12 = (cont12*fact[p.second])%MOD;
	}
	
	printf("%lld\n", ((fact[n] - ( cont1 + cont2)%MOD + cont12)%MOD + MOD)%MOD);

	return 0;
}