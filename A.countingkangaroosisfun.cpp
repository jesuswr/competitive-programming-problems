#include <iostream>
#include <algorithm>

using namespace std;

int arr[5*(int)1e5 + 5];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr,arr+n,greater<int>());
	
	int ans = n;
	int i = 0;
	int j = n/2;
	while(i<n/2 && j<n) {
	    if (arr[i] >= 2* arr[j])
	    {
	    	ans--;
	    	i++;
	    	j++;
	    }
	    else
	    {
	    	j++;
	    }
	}
	printf("%d\n", ans);
}
