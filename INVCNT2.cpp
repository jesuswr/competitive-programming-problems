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
const int maxN = 200000 + 5; // CAMBIAR ESTE

// GJNM
pii arr[maxN];
ll query[4*maxN];
ll cont;
int n;

ll get_sum( int s , int e , int qs , int qe , int ind )
{
	if ( qs <= s && e <= qe ) return query[ind];
	if ( s > qe || e < qs ) return 0;
	int m = ( s + e ) / 2;
	return get_sum( s , m , qs , qe , 2*ind+1 ) + get_sum( m+1 , e , qs , qe , 2*ind+2);
}

void update_val( int s , int e , int pos , int ind )
{
	if ( pos < s || pos > e ) return;
	query[ind]++;
	if ( s != e )
	{
		int m = ( s + e ) / 2;
		update_val( s , m , pos , 2*ind+1);
		update_val( m+1 , e , pos , 2*ind+2);
	}
}


int main()
{
	int t;
	ri(t);
	while(t--) 
	{
	    n;
	    ri(n);
	    for (int i = 0; i < 4*n; ++i)
	    {
	    	query[i] = 0;
	    }
	    for (int i = 0; i < n; ++i)
	    {
	    	ri(arr[i].first);
	    	arr[i].second = i;
	    }
	    sort(arr,arr+n,greater<pii>());
	    cont = 0;
	    for (int i = 0; i < n; ++i)
	    {
	    	cont += get_sum( 0 , n-1 , 0, arr[i].second - 1 , 0 );
	    	update_val( 0 , n-1 , arr[i].second , 0 );
	    }
	    printf("%lld\n", cont);


	}

	return 0;
}