#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

#include "WordInfo.hpp"

using namespace std;

class Item {
   public:
    Item(WordInfo& info);
    virtual ~Item();
    WordInfo value;

    Item* left;
    Item* right;
};

class BinaryTree {
   private:
    Item* root;
    int length;
    void insert(Item* item, Item** node);
    void preOrder(Item* node);

   public:
    BinaryTree();
    virtual ~BinaryTree();
    void push(WordInfo& info);
    // void remove(Item item);
    void showPreOrder();
};

#endif