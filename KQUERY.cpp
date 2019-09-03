#include <iostream>
#include <algorithm>


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;


#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);

const int maxN = 30005; // CAMBIAR ESTE

// GJNM
pii numbs[maxN];
int n, q;
int query[4*maxN];
int qI[200006], qJ[200006], qK[200006], ans[200006];
pii quer[200006];

void addVal( int start, int end, int pos, int ind )
{
	if (pos < start || pos > end) return;
	query[ind]++;
	if (start!=end) 
	{
		int mid = ( start + end ) / 2;
		addVal( start, mid , pos , 2*ind+1);
		addVal( mid+1,end,pos,2*ind+2);
	}
}

int getVal( int s, int e, int qs, int qe, int ind)
{
	if ( qs <= s && e <= qe ) return query[ind];
	if ( e < qs || s > qe) return 0;
	int mid = ( s + e ) / 2;
	return getVal (s,mid,qs,qe,2*ind+1) + getVal(mid+1,e,qs,qe,2*ind+2);
}


int main()
{
	
	ri(n);
	for (int i = 0; i < 4*n; ++i)
	{
		query[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		ri(numbs[i].first);
		numbs[i].second = i;
	}
	ri(q);
	int aux1, aux2, aux3;
	for (int i = 0; i < q; ++i)
	{
		riii(aux1,aux2,aux3);
		qI[i] = aux1-1;
		qJ[i] = aux2-1;
		qK[i] = aux3;
		quer[i] = {aux3,i};
	}
	sort(quer, quer + q, greater<pii>());
	sort(numbs, numbs + n, greater<pii>());
	int curr = 0;

	for ( int i = 0; i<q ; i++)
	{
		int ind2 = quer[i].second;
		int k = quer[i].first;

		for (curr; curr < n && numbs[curr].first > k; ++curr)
		{
			addVal( 0 , n - 1, numbs[curr].second , 0);
		}
		ans[ind2] = getVal(0,n-1,qI[ind2],qJ[ind2],0);
	}
	
	for (int i = 0; i < q; ++i)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}