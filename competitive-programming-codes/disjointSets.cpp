// Codigo de Conjuntos Disjuntos

#include <iostream>

const int maxN = 1001;
int father[maxN], siz[maxN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m){
	for (int i = n; i <= m; ++i){
		father[i] = -1;
		siz[i] = 0;
	}
}
int find(int x){
	if (father[x]==-1) 
		return x;
	return father[x] = find(father[x]);
}
void unio(int x, int y){
	if (siz[x] > siz[y]) 
		father[y] = x;
	else{
		father[x] = y;
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}
