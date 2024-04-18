//Savana Thomas COP 3502 Lab 10

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
struct Trie
{
	int count;
	struct Trie* children[26];
};

struct Trie* createTrie();

// Inserts the word to the trie structure
void insert(struct Trie* pTrie, char* word)
{
	int key = 0;
	for (key = 0; key <= strlen(word); key++) {
		if (key == strlen(word)) {
			pTrie->count += 1;
			return;
		}
		int index = word[key] - 'a';

		if (pTrie->children[index] == NULL) {
			pTrie->children[index] = createTrie();
		}
		pTrie = pTrie->children[index];
	}	
}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie* pTrie, char* word)
{
	int key = 0;
	for (key = 0; key <= strlen(word); key++) {
		if (key == strlen(word)) {
			return 0;
		}

		if (key == strlen(word) - 1) {
			int index = word[key] - 'a';
			if (pTrie->children[index] != NULL)
				return pTrie->children[index]->count;
			else
				return 0;
		}
		int index = word[key] - 'a';
		if (pTrie->children[index] == NULL) {
			return 0;
		}
		pTrie = pTrie->children[index];
	}
}

// deallocate the trie structure
struct Trie* deallocateTrie(struct Trie* pTrie)
{
	for (int i = 0; i < 26; i++) {
		if (pTrie->children[i] != NULL)
			deallocateTrie(pTrie->children[i]);
	}

	free(pTrie);
	return NULL;
}

// Initializes a trie structure
struct Trie* createTrie()
{
	struct Trie* myTree = malloc(sizeof(struct Trie));
	myTree->count = 0;

	for (int i = 0; i < 26; i++) {
		myTree->children[i] = NULL;
	}
	return myTree;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char* filename, char** pInWords)
{
	FILE* filePtr = fopen(filename, "r");
	int num;
	fscanf(filePtr, "%d", &num);
	for (int i = 0; i < num; i++) {
		pInWords[i] = malloc(sizeof(50));
		fscanf(filePtr, "%s\n", pInWords[i]);
	}
	return num;
}

int main(void)
{
	char* inWords[256];

	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i = 0; i < numWords; ++i)
	{
		printf("%s\n", inWords[i]);
	}

	struct Trie* pTrie = createTrie();
	for (int i = 0; i < numWords; i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char* pWords[] = { "notaword", "ucf", "no", "note", "corg" };
	for (int i = 0; i < 5; i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}