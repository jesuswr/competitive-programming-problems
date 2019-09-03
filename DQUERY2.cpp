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
const int maxN = 30005; // CAMBIAR ESTE

// GJNM
int arr[maxN];
int pre[(int)1e6 + 5];
piii qr[200005];
int ans[200005];
int bit[maxN];
int n;

void update( int ind , int val )
{
	while( ind <= n) 
	{
		//printf("%d\n",ind);
	    bit[ind] += val;
	    ind += ( ind & -ind);
	}
}

int getsum( int ind )
{
	int s = 0;
	while( ind > 0) 
	{
	    s += bit[ind];
	    ind -= ( ind & -ind );
	}
	return s;
}



int main()
{

	ri(n);
	for (int i = 1; i <= n; ++i)
	{
		ri(arr[i]);
		pre[arr[i]] = -1;
	}
	for (int i = 0; i < n+1; ++i)
	{
		bit[i] = 0;
	}
	int q;
	ri(q);
	int qi, qj;
	for (int i = 0; i < q; ++i)
	{
		rii(qi,qj);
		qr[i] = {qj,{qi,i}};
	}
	sort( qr , qr + q);
	int curr = 0;
	int ind;
	for (int i = 1; i <= n; ++i)
	{
		if ( curr == q ) break;
		if ( pre[arr[i]] != -1 ) update( pre[arr[i]] , -1 );
		pre[arr[i]] = i;
		update( i , 1 );
		
		for (curr; curr < q && qr[curr].first <= i; ++curr)
		{
			ans[qr[curr].second.second] = getsum(qr[curr].first) - getsum(qr[curr].second.first-1);
		}
	}
	for (int i = 0; i < q; ++i)
	{
		printf("%d\n", ans[i]);
	}
	

	return 0;
}