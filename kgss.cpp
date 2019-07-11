#include <iostream>


using namespace std;

typedef pair<int,int> pii;

const int maxN = 300005;
int n;
int numbs[100005];
pii query[maxN];


pii getMaxBP (pii p1, pii p2)
{
	if (p1.first >= p2.first)
	{
		return {p1.first, max(p1.second,p2.first)};
	}
	return {p2.first, max(p2.second,p1.first)};
}


pii getMaxBPI (pii p1, int i)
{
	if (i > p1.first) return {i,p1.first};
	if (i > p1.second) return {p1.first,i};
	return p1;
}


pii makeSet(int start, int end, int index)
{
	if (start==end)
	{
		return query[index] = {numbs[start],0};
	}
	int mid = start + (end-start)/2;
	query[index] = getMaxBP(makeSet(start, mid, 2*index+1), makeSet(mid+1, end, 2*index+2));
	return query[index];
}


pii updateVal(int start, int end, int indexTU, int index, int newVal)
{
	if ( start == end && indexTU==start)
	{
		query[index] = {newVal,0};
		return query[index];
	}
	if ( indexTU > end || indexTU < start ) return query[index];

	int mid = start + (end-start)/2;
	query[index] = getMaxBP( updateVal(start, mid, indexTU, 2*index+1, newVal), updateVal(mid+1, end, indexTU, 2*index+2, newVal) );
	return query[index];

}


pii getRangeS(int start, int end, int queryS, int queryE, int index)
{
	if (start>=queryS && end<=queryE) return query[index];
	if (end<queryS || start>queryE) return {0,0};

	int mid = start + (end-start)/2;
	return getMaxBP( getRangeS(start, mid, queryS, queryE, 2*index+1), getRangeS(mid+1, end, queryS, queryE, 2*index+2) );
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numbs[i]);
	}
	makeSet(0, n-1, 0);
	int p,q;
	pii ans;
	char c;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%*c%c%d%d", &c, &p, &q);
		
		if (c == 'Q')
		{
			ans = getRangeS(0, n-1, p-1, q-1, 0);
			p = ans.first + ans.second;
			printf("%d\n", p);	
		}
		else updateVal(0,n-1,p-1,0,q);
		
	}

}