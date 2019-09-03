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
int bit[maxN];
int qI[200006], qJ[200006], qK[200006], ans[200006];
pii quer[200006];

void addVal ( int ind , int val )
{
	while( ind <= n) 
	{
	    bit[ind] += val;
	    ind += ( ind & -ind );
	}
}

int getVal ( int ind )
{
	int s = 0;
	while(ind > 0) 
	{
	    s += bit[ind];
	    ind -= ( ind & -ind );
	}
	return s;
}


int main()
{
	
	ri(n);
	for (int i = 0; i <= n; ++i)
	{
		bit[i] = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		ri(numbs[i].first);
		numbs[i].second = i;
	}
	ri(q);
	int aux1, aux2, aux3;
	for (int i = 0; i < q; ++i)
	{
		riii(aux1,aux2,aux3);
		qI[i] = aux1;
		qJ[i] = aux2;
		qK[i] = aux3;
		quer[i] = {aux3,i};
	}
	sort(quer, quer + q, greater<pii>());
	sort(numbs+1, numbs + n+1, greater<pii>());
	int curr = 1;

	for ( int i = 0; i<q ; i++)
	{
		int ind2 = quer[i].second;
		int k = quer[i].first;

		for (curr; curr <= n && numbs[curr].first > k; ++curr)
		{
			addVal( numbs[curr].second , 1);
		}
		ans[ind2] = getVal(qJ[ind2]) - getVal(qI[ind2]-1);
	}
	
	for (int i = 0; i < q; ++i)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}