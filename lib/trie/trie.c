#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define ALPHABET_SIZE 26

typedef struct Node {
  struct Node* letters[ALPHABET_SIZE];
  int isLeaf;
} Node;

struct Trie {
  Node* root;
};

/* HELPERS */

int char_to_ord(char c)
{
  return tolower(c) - 'a';
}

char ord_to_chard(int index)
{
  return index + 'a';
}

int has_letters(Node* n)
{
  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    if (n->letters[i] != NULL) {
      return 1;
    }
  }

  return 0;
}

int __trie_count_words(Node* node)
{
  int counter = 0;
  Node* current = node;

  if (current == NULL) {
    return 0;
  }

  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    if (current->letters[i] != NULL) {
      counter += __trie_count_words(current->letters[i]);
    }
  }

  if (current->isLeaf) {
    counter += 1;
  }

  return counter;
}

void __trie_print_words(Node* node, int level, char* word)
{
  Node* current = node;

  if (current == NULL) {
    return;
  }

  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    if (current->letters[i] != NULL) {
      word[level] = ord_to_chard(i);
      __trie_print_words(current->letters[i], level + 1, word);
    }
  }

  if (current->isLeaf) {
    word[level] = '\0';
    printf("%s\n", word);
    return;
  }
}

Node* __trie_remove(Node* node, char* word, int level)
{
  Node* current = node;

  if (current == NULL) {
    return NULL;
  }

  int word_length = strlen(word);
  if (word_length == level) {
    if (current->isLeaf) {
      current->isLeaf = 0;
    }

    if (!has_letters(current)) {
      free(current);
      current = NULL;
    }

    return current;
  }

  int index = char_to_ord(word[level]);
  current->letters[index] = __trie_remove(current->letters[index], word, level + 1);

  if (!current->isLeaf && !has_letters(current)) {
    free(current);
    current = NULL;
  }

  return current;
}

Node* node_create_trie(void)
{
  Node* n = malloc(sizeof(Node));

  if (n == NULL) {
    fprintf(stderr, "could not initialize trie");
    exit(1);
  }

  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    n->letters[i] = NULL;
  }

  n->isLeaf = 0;

  return n;
}

/* IMPLEMENTATION */

Trie* trie_create(void)
{
  Trie* t = malloc(sizeof(Trie));

  if (t == NULL) {
    fprintf(stderr, "could not initialize trie");
    exit(1);
  }

  t->root = node_create_trie();

  return t;
}

int trie_count_words(Trie* t)
{
  return __trie_count_words(t->root);
}

void trie_print_words(Trie* t)
{
  char word[256];
  __trie_print_words(t->root, 0, word);
}

void trie_insert(Trie* t, char* word)
{
  Node* current = t->root;
  int word_length = strlen(word);

  for (int i = 0; i < word_length; ++i) {
    int index = char_to_ord(word[i]);
    printf("%d -> %c\n", index, word[i]);

    if (current->letters[index] == NULL) {
      current->letters[index] = node_create_trie();
    }

    current = current->letters[index];
  }

  current->isLeaf = 1;
}

void trie_remove(Trie* t, char* word)
{
  __trie_remove(t->root, word, 0);
}

int trie_lookup(Trie* t, char* word)
{
  Node* current = t->root;
  int word_length = strlen(word);

  for (int i = 0; i < word_length; ++i) {
    int index = char_to_ord(word[i]);

    if (current->letters[index] == NULL) {
      return 0;
    }

    current = current->letters[index];
  }

  return current->isLeaf;
}
