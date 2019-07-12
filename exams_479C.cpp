#include <iostream>
#include <algorithm>

using namespace std;	


pair<int,int> dates[5001];


int main()
{
	int n; 
	scanf("%d",&n);
	int n1, n2;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &n1, &n2);
		dates[i] = {n1,n2};
	}
	sort(dates, dates+n);
	int currentDate = 0;
	for (int i = 0; i < n; ++i)
	{
		if (currentDate<=dates[i].second) currentDate = dates[i].second;
		else currentDate = dates[i].first;
	}
	printf("%d\n", currentDate);
}