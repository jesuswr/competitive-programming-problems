#include <iostream>
#include <algorithm>


using namespace std;

int n;
pair<int,int> ballons[1001];
int diff;
int a1, a2;




int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &ballons[i].first);
		ballons[i].second = i+1;
	}
	if (n==1)
	{
		printf("-1\n");
		return 0;
	}
	if (n==2 && ballons[0].first==ballons[1].first)
	{
		printf("-1\n");
		return 0;
	}
	n--;
	printf("%d\n",n);
	n++;
	sort(ballons, ballons + n);
	for (int i = 1; i < n; ++i)
	{
		printf("%d ", ballons[i].second);
	}
	printf("\n");
}
