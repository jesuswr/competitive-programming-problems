#include <iostream>


using namespace std;



const int maxN = 200000;
int n;
int numbs[100001];
long long query[maxN];


/*
- st its the array that represents the tree
- arr is the array of numbers
- start is the start of the range of the current node
- end is the end of the range of the current node
- ind is the index of the current node
*/
long long makeST(long long *st, int *arr, int start, int end, int ind)
{
	if ( start == end )
	{
		query[ind] = (long long)arr[start];
		return query[ind];
	}

	int middle = start + (end - start)/2;
	query[ind] = makeST(st, arr, start, middle, 2*ind+1) + makeST(st, arr, middle+1, end, 2*ind+2);
	return query[ind];
}


/*
- st its the array that represents the tree
- start is the start of the range of the current node
- end is the end of the range of the current node
- sRange is the beggining of the range asked by the query
- eRange is the ending of the range asked by the query
- index is the index of the current node
*/
long long getValue(long long *st, int start, int end, int sRange, int eRange, int index)
{
	if (start>=sRange && end<=eRange) return st[index];
	if (end < sRange || start > eRange) return 0;

	int middle = start + (end - start)/2;
	return getValue (st, start, middle, sRange, eRange, 2*index+1) + getValue(st, middle + 1, end, sRange, eRange, 2*index+2);
}


void uptVal(long long *st, int start, int end, int index, int diff)
{
	if (index < start || index > end) return;

	st[index] += diff;

	if (start != end) 
	{
		int middle = start + (end - start)/2;
		uptVal(st, start, middle, 2*index+1, diff);
		uptVal(st, middle+1, end, 2*index + 2, diff);
	}
}



void updateValue(long long *st, int end, int ind, int newVal)
{
	int difference = newVal - numbs[ind];

	numbs[ind] = newVal;

	uptVal(st, 0, end, 0, difference);
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numbs[i]);
	}
	makeST(query, numbs, 0, n-1, 0);
	int p,q;
	char c;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%*c%c%d%d", &c, &p, &q);
		//printf("%d %d \n", p, q);
		if (c == 'Q')
		{
			
			long long ans = getValue(query, 0, n-1, p-1, q-1, 0);
			printf("%lld\n", ans);
		}
		else updateValue(query, n-1, p-1, q);
	}

}