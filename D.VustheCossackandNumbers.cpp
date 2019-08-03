#include <iostream>

using namespace std;

double arr[int(1e5)+5];


int main(){
	int n;
	scanf("%d", &n);
	double aux;
	long long count = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &arr[i]);
		count += (long long)arr[i];
	}
	

	for (int i = 0; i < n; ++i)
	{
		if (count == 0) break;
		if (count > 0 && arr[i]<0 && arr[i]-int(arr[i])!=0)
		{
			arr[i]--;
			count--;
		}
		if (count < 0 && arr[i]>0 && arr[i]-int(arr[i])!=0)
		{
			arr[i]++;
			count++;
		}
	}
	int aux2;
	for (int i = 0; i < n; ++i)
	{
		aux2 = (int)arr[i];
		printf("%d\n", aux2);
	}
}
