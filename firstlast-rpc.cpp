#include <iostream>
#include <set>


using namespace std;

const int maxN = 1e5+5;


int arr[maxN];
int arr2[maxN];



int main()
{
	int n;
	scanf("%d", &n);
	int before, after;
	arr2[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		arr2[i+1] = 0;
	}
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr2[arr[i]-1] == 0)
		{
			arr2[arr[i]] = 1;
		}
		else
		{
			arr2[arr[i]] = arr2[arr[i]-1] + 1;
		}
		mx = max( mx, arr2[arr[i]] );
	}
	int ans = n - mx;
	printf("%d\n", ans);
}
