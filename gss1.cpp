#include <iostream>


using namespace std;

struct node
{
	long long maxSum, totalSum, maxLeftSum, maxRightSum;
};


const int maxN = 200010;
const long long Inf = 750349999;

int numbs[50010];
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
	int n1, n2;
	node ans;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &n1, &n2);
		ans = getMaxSum(0, n-1, 0, n1-1, n2-1);
		printf("%lld\n", ans.maxSum);
		
	}
}