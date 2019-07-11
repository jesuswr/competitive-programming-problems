#include <iostream>


using namespace std;

struct node
{
	long long maxSum, totalSum, maxLeftSum, maxRightSum;
};


const int maxN = 4*50010;
const long long Inf = 750349999;

int numbs[50020];
node query[maxN];
int n;

node makeSet(int start, int end, int index)
{
	if (start == end) return query[index] = { numbs[start], numbs[start], numbs[start], numbs[start] };

	int mid = (start + end)/2;

	node leftChild = makeSet(start, mid, 2*index+1);
	node rightChild = makeSet(mid + 1, end, 2*index+2);

	query[index].totalSum = leftChild.totalSum + rightChild.totalSum;
	query[index].maxLeftSum = max( leftChild.maxLeftSum, leftChild.totalSum + rightChild.maxLeftSum );
	query[index].maxRightSum = max( rightChild.maxRightSum, rightChild.totalSum + leftChild.maxRightSum );
	query[index].maxSum = max ( max( leftChild.maxSum, rightChild.maxSum ), leftChild.maxRightSum + rightChild.maxLeftSum );
	return query[index];
}

node getMaxSum(int start, int end, int index, int queryStart, int queryEnd)
{
	if ( start > queryEnd || end < queryStart ) return {-Inf,-Inf,-Inf,-Inf};

	if ( start >= queryStart && end <= queryEnd ) return query[index];

	int mid = (start + end)/2;

	node leftChild = getMaxSum(start, mid, 2*index+1, queryStart, queryEnd);
	node rightChild = getMaxSum(mid+1, end, 2*index+2, queryStart, queryEnd);

	node retThis;
	retThis.totalSum = leftChild.totalSum + rightChild.totalSum;
	retThis.maxLeftSum = max( leftChild.maxLeftSum, leftChild.totalSum + rightChild.maxLeftSum );
	retThis.maxRightSum = max( rightChild.maxRightSum, rightChild.totalSum + leftChild.maxRightSum );
	retThis.maxSum = max ( max( leftChild.maxSum, rightChild.maxSum ), leftChild.maxRightSum + rightChild.maxLeftSum );
	return retThis;
}

node updateValue(int start, int end, int index, int indexToChange, int newValue)
{
	if (start == end && end == indexToChange) return query[index] = {newValue,newValue,newValue,newValue};
	
	if (start>indexToChange || end<indexToChange) return query[index];

	int mid = (start + end)/2;
	node leftChild = updateValue (start, mid, 2*index+1, indexToChange, newValue);
	node rightChild = updateValue (mid+1, end, 2*index+2, indexToChange, newValue);

	query[index].totalSum = leftChild.totalSum + rightChild.totalSum;
	query[index].maxLeftSum = max( leftChild.maxLeftSum, leftChild.totalSum + rightChild.maxLeftSum );
	query[index].maxRightSum = max( rightChild.maxRightSum, rightChild.totalSum + leftChild.maxRightSum );
	query[index].maxSum = max ( max( leftChild.maxSum, rightChild.maxSum ), leftChild.maxRightSum + rightChild.maxLeftSum );
	return query[index];
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numbs[i]);
	}
	makeSet(0,n-1,0);
	int m;
	scanf("%d", &m);
	int op, n1, n2;
	node ans;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &op, &n1, &n2);
		if (op == 0) updateValue(0,n-1,0,n1-1,n2);
		else
		{
			ans = getMaxSum(0, n-1, 0, n1-1, n2-1);
			printf("%lld\n", ans.maxSum);
		}
	}
}