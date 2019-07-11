#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int n;









int main()
{
	int t;
	scanf("%d",&t);
	int aux;
	int max1, max2, max3;
	int ans1, ans2;
	for (int ii = 0; ii < t; ++ii)
	{
		scanf("%d",&n);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&aux);
			vec.push_back(aux);
		}

		sort(vec.rbegin(),vec.rend());

		max1 = 0, max2 = 0, max3 = 0;

		for (int i = 1; i < n; ++i)
		{
			if ( vec[0]%vec[i] != 0 )
			{
				max2 = i;
				break;
			}
		}

		for (int i = max2+1; i < n; ++i)
		{
			if ( vec[0]%vec[i] != 0 && vec[max2]%vec[i] != 0)
			{
				max3 = i;
				break;
			}
		}

		max1 = vec[max1];
		max2 = vec[max2];
		max3 = vec[max3];
		//printf("%d %d %d\n", max1,max2,max3);
		ans1 = max1;
		if (max2!=max1)
		{
			ans1 += max2;
		}
		if (max3!=max1)
		{
			ans1 += max3;
		}
		ans2=0;
		if (max1%30==0){
			int h = 0;
			for (int i = 0; i < n; ++i)
			{
				if (max1/2 == vec[i] || max1/3 == vec[i] || max1/5 == vec[i])
				{
					h++;
				}
			}
			if (h==3)
			{
				ans2 = max1/2 + max1/3 + max1/5;
			}
		}

		printf("%d\n", max(ans1,ans2));
		vec.clear();
		}
	}