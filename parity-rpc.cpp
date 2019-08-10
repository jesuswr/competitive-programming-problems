#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char word[75];
int parity[30];

int main()
{
	scanf("%s", word);
	int n = strlen(word);
	for (int i = 0; i < 30; ++i)
	{
		parity[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		parity[ (int)word[i] - 'a' ] += 1;
	}
	bool even = true;
	bool odd = true;
	for (int i = 0; i < 26; ++i)
	{
		
		if (parity[i]==0) continue;
		if (parity[i]%2==0)
		{
			odd = false;
		}
		else
		{
			even = false;
		}
	}
	if (odd) printf("1\n");
	else if (even) printf("0\n");
	else printf("2\n");

}
