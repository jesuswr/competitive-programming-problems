#include <iostream>
#include <string>

using namespace std;

class trie_node{
public:
	trie_node *next[26];
	int cnt;

	trie_node(){
		for(int i=0; i<26; i++)
			next[i] = NULL;
		cnt = 0;
	}
};

class trie{
public:
	trie_node *root;

	trie(){
		root = new trie_node;
	}

	void insert(string &s){
		trie_node *aux = root;
		for (char c : s){
			int index = c - 'a';
			if ( aux->next[index] == NULL ){
				aux->next[index] = new trie_node;
			}
			aux = aux->next[index];
		}
		aux->cnt++;
	}

	int find(string &s){
		trie_node *aux = root;
		for (char c : s){
			int index = c - 'a';
			if ( aux->next[index] == NULL ){
				return 0;
			}
			aux = aux->next[index];
		}
		return aux->cnt;
	}
};


int main(){
	trie my_trie;

	string s = "abcdefghijklmnopqrstuvwxyz";
	my_trie.insert(s);
	string s2 = "abcdei";
	my_trie.insert(s2);
}