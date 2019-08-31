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
int arr[maxN];
int aux1[maxN];
int aux2[maxN];
ll cont;
int n;

void merge( int start , int mid , int end )
{
	int i = 0;
	int j = 0;
	for (int k = start; k <= mid; ++k)
	{
		aux1[i] = arr[k];
		i++;
	}
	int maxI = i;
	for (int k = mid+1; k <= end; ++k)
	{
		aux2[j] = arr[k];
		j++;
	}
	int maxJ = j;
	i = j = 0;
	int p = start;
	while( i < maxI || j < maxJ ) 
	{
	    if ( i == maxI)
	    {
	    	arr[p] = aux2[j];
	    	p++;
	    	j++;
	    }
	    else if ( j == maxJ )
	    {
	    	arr[p] = aux1[i];
	    	cont += j;
	    	i++;
	    	p++;
	    }
	    else if ( aux1[i] >= aux2[j] )
	    {
	    	arr[p] = aux2[j];
	    	j++;
	    	p++;
	    }
	    else
	    {
	    	arr[p] = aux1[i];
	    	cont += j;
	    	i++;
	    	p++;
	    }
	}
}



void merge_sort( int s, int e )
{
	if ( s < e )
	{
		int mid = ( s + e ) / 2;
		merge_sort( s , mid );
		merge_sort( mid + 1, e );
		merge( s , mid , e );
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
	    for (int i = 0; i < n; ++i)
	    {
	    	ri(arr[i]);
	    }
	    cont = 0;
	    merge_sort(0,n-1);
	    printf("%lld\n", cont);
	}
	return 0;
}