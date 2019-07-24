#include <iostream>

using namespace std;

int n;
int radius[int(2e5+5)];

bool checkLeft(int index)
{
	
	for (int i = index-1; i >-1; --i)
	{
		if (radius[i] < radius[i+1]) continue;
		return false;
	}
	
	return true;
}

bool checkRight(int index)
{
	
	for (int i = index; i < n-1; ++i)
	{
		if (radius[i] > radius[i+1]) continue;
		return false;
	}
	
	return true;
}






int main()
{
	scanf("%d", &n);
	int maxI = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &radius[i]);
		if (radius[i]>radius[maxI])
		{
			maxI = i;
		}
	}

	if (checkLeft(maxI) && checkRight(maxI)) printf("YES\n");
	else printf("NO\n");
	return 0;

}
