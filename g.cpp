#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int candys[10000000];
int candysNotImportant[10000000];
int used[10000000];

int main(){
	int q;
	int n;
	int aux;
	int like;
	int cont,cont2;
	scanf("%d",&q);
	for (int k = 0; k < q; k++)
	{
		scanf("%d",&n);
		cont = 0;
		cont2 = 0;
		for (int i = 0; i <= n; i++)
		{
			candys[i] = 0;
			candysNotImportant[i] = 0;
			used[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d",&aux,&like);
			candysNotImportant[aux] = candysNotImportant[aux] + 1;
			if (like==1){
				candys[aux] = candys[aux] + 1;
			}
		}
		sort(candys,candys+n+1, greater<int>());
		sort(candysNotImportant,candysNotImportant+n+1, greater<int>());
		
		for (int i = 0; i < n; i++)
		{
			if (!used[candys[i]]){
				cont = cont + candys[i];
				used[candys[i]] = 1;
			}
			else{
				while(used[candys[i]]) {
				    candys[i] = candys[i] - 1;
				}
				cont = cont + candys[i];
				used[candys[i]] = 1;
			}
			if (candys[i]==0){
				break;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			used[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			if (!used[candysNotImportant[i]]){
				cont2 = cont2 + candysNotImportant[i];
				used[candysNotImportant[i]] = 1;
			}
			else{
				while(used[candysNotImportant[i]]) {
				    candysNotImportant[i] = candysNotImportant[i] - 1;
				}
				cont2 = cont2 + candysNotImportant[i];
				used[candysNotImportant[i]] = 1;
			}
			if (candysNotImportant[i]==0){
				break;
			}
		}
		printf("%d %d\n",cont2,cont );
	}
}