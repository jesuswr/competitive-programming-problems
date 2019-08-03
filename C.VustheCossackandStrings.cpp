#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int count[int(1e6)+1];

int main(){
	char word1[int(1e6)+1];
	char word2[int(1e6)+1];
	scanf("%s", word1);
	scanf("%s", word2);
	int l1 = strlen(word1);
	int l2 = strlen(word2);
	int contador = 0;
	count[0] = int(word1[0]-'0');
	for (int i = 1; i < l1; ++i)
	{
		count[i] = count[i-1] + int(word1[i]-'0');
	}
	for (int i = 0; i < l2; ++i)
	{
		contador += int(word2[i]-'0');
	}
	int ans = 0;
	if ( (count[l2-1]-contador)%2==0 ) ans++;
	for (int i = 1; i < l1-l2+1; ++i)
	{
		if ( ( (count[i+l2-1] - count[i-1]) - contador )%2 ==0 )
		{
			ans++;
		}
	}
	printf("%d\n", ans);
}
