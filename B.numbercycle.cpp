#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>




using namespace std;


int ans[int(1e5)+5];

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> numbs(n,0);
	for (int i = 0; i < n; ++i)
	{
		//printf("hola\n");
		scanf("%d", &numbs[i]);
	}
	sort(numbs.begin(), numbs.end(), greater<int>());
	ans[0] = numbs[n-1];
	numbs.pop_back();
	queue<int> leftq;
	queue<int> rightq;
	leftq.push(n-1);
	rightq.push(1);
	int leftaux, rightaux;
	while(true) 
	{
		if (numbs.empty()) break;
	   	leftaux = leftq.front();
	   	leftq.pop();
	   	rightaux = rightq.front();
	   	rightq.pop();
		if ( leftaux < rightaux ) break;
	   	ans[ rightaux ] = numbs[numbs.size()-1];
	   	numbs.pop_back();
	   	rightq.push(rightaux+1);
	   	
	   	if (numbs.empty()) break;
	   	if ( rightaux == leftaux ) continue;

	   	ans [ leftaux ] = numbs[numbs.size()-1];
	   	numbs.pop_back();
	   	leftq.push(leftaux-1);
	}

	bool cond = false;
	if ( ans[0] < ans[n-1] + ans[1] && ans[n-1] < ans[n-2] + ans[0]) cond = true;
	if (cond)
	{
		for (int i = 1; i < n-1; ++i)
		{
			if ( ans[i] < ans[i-1] + ans[i+1] ) continue;
			cond = false;
			break;
		}
	}
	if (cond)
	{
		printf("YES\n");
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}

}
