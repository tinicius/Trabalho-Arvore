#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include <iostream>
#include <fstream>
#include <queue>

#include "WordInfo.hpp"

using namespace std;

typedef struct Node {
    Node* left;
    Node* right;

    WordInfo* info;
    int prob;

} Node;

void createHuffmanTree(vector<WordInfo>& elements, ofstream& file);

#endif