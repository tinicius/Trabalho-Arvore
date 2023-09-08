#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

#include "Item.hpp"
#include "WordInfo.hpp"

using namespace std;

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