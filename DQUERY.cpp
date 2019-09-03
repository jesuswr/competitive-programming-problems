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
int query[4*maxN];

int getsum( int s , int e , int qs , int qe , int ind )
{
	if ( qs <= s && e <= qe ) return query[ind];
	if ( s > qe || e < qs ) return 0;
	int m = ( s + e ) / 2;
	return getsum( s , m , qs , qe , 2*ind+1 ) + getsum( m+1 , e , qs , qe , 2*ind+2);
}

void update( int s , int e , int pos , int val , int ind )
{
	if ( pos < s || pos > e ) return;
	query[ind] += val;
	if ( s != e )
	{
		int m = ( s + e ) / 2;
		update (s,m,pos,val,2*ind+1);
		update (m+1,e,pos,val,2*ind+2);
	}
}



int main()
{

	int n;
	ri(n);
	for (int i = 0; i < n; ++i)
	{
		ri(arr[i]);
		pre[arr[i]] = -1;
	}
	for (int i = 0; i < 4*n; ++i)
	{
		query[i] = 0;
	}
	int q;
	ri(q);
	int qi, qj;
	for (int i = 0; i < q; ++i)
	{
		rii(qi,qj);
		qr[i] = {qj-1,{qi-1,i}};
	}
	sort( qr , qr + q);
	int curr = 0;
	int ind;
	for (int i = 0; i < n; ++i)
	{
		if ( curr == q ) break;
		if ( pre[arr[i]] != -1 ) update( 0 , n-1 , pre[arr[i]] , -1 , 0);
		pre[arr[i]] = i;
		update( 0 , n-1 , i , 1 , 0);
		
		for (curr; curr < q && qr[curr].first <= i; ++curr)
		{
			ans[qr[curr].second.second] = getsum(0,n-1,0,qr[curr].first,0) - getsum(0,n-1,0,qr[curr].second.first-1,0);
		}
	}
	for (int i = 0; i < q; ++i)
	{
		printf("%d\n", ans[i]);
	}
	

	return 0;
}