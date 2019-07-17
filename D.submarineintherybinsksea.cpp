#include <iostream>
#include <vector>


using namespace std;
const int numeroraro= 998244353;
const int maxN = 100001;
vector<int> numeros[maxN];


unsigned long long getNum(int i)
{
	
	unsigned long long numb = 0;
	for (int k = numeros[i].size()-1; k > -1; k--)
	{
		
		numb = (unsigned long long)numb*10;
		numb = numb + (unsigned long long)numeros[i][k];
		numb = (unsigned long long)numb*10;
		
	}

	return numb;
}

unsigned long long getNum2(int i)
{
	
	unsigned long long numb = numeros[i][numeros[i].size()-1];
	if (numeros[i].size()==1) return numb;
	numb = numb *10;
	for (int k = numeros[i].size()-2; k > 0; k--)
	{
		
		numb = (unsigned long long)numb*10;
		numb = numb + (unsigned long long)numeros[i][k];
		numb = (unsigned long long)numb*10;
		
		
	}
	numb = numb*10;
	numb += numeros[i][0];

	return numb;
}


int main()
{
	int n;
	scanf("%d", &n);
	int aux;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&aux);
		while(aux>0) {
		    numeros[i].push_back(aux%10);
		    aux = aux/10;
		}
	}
	unsigned long long ans = 0;
	
	
	for (int j = 0; j < n; ++j)
	{
			
		ans = (unsigned long long) ans + n*((getNum(j)+getNum2(j))%numeroraro);
		ans = (unsigned long long) ans%numeroraro;
	}
	
	printf("%llu\n", ans);

}