#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>

#include "Item.hpp"
#include "WordInfo.hpp"

using namespace std;

class AvlTree {
   private:
    Item* root;
    int length;
    void insert(Item* item, Item** node);
    void preOrder(Item* node);

   public:
    AvlTree();
    virtual ~AvlTree();
    void push(WordInfo& info);
    // void remove(Item item);
    void showPreOrder();

    int height(Item* node);
    int balanceFactor(Item* node);

    void rotateLeft(Item** node);
    void rotateRight(Item** node);
    void rotateDoubleLeft(Item** node);
    void rotateDoubleRight(Item** node);
};

#endif