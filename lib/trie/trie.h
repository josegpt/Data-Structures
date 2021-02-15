#ifndef TRIE_H
#define TRIE_H

typedef struct Trie Trie;

Trie* trie_create(void);
void trie_insert(Trie* t, char* word);
void trie_remove(Trie* t, char* word);
int trie_lookup(Trie* t, char* word);
int trie_count_words(Trie* t);
void trie_print_words(Trie* t);
#endif // TRIE_H
