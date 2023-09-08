#include "AvlTree.hpp"

#define dbg(x) cout << #x << " = " << x << endl

AvlTree::AvlTree() {
    this->root = nullptr;

    length = 0;
}

AvlTree::~AvlTree() {}

int max(int& a, int& b) {
    if (a >= b)
        return a;
    else
        return b;
}

void AvlTree::rotateLeft(Item** node) {}

void AvlTree::rotateDoubleLeft(Item** node) {}

void AvlTree::rotateDoubleRight(Item** node) {}

void AvlTree::rotateRight(Item** node) {}

void AvlTree::insert(Item* item, Item** node) {
    if (*node == NULL) {
        *node = item;
        (*node)->weight = 0;
    } else if(item->value.frequency < (*node)->value.frequency) {
        insert(item, &(*node)->left);
    } else {
        insert(item, &(*node)->right);
    }
}

void AvlTree::preOrder(Item* node) {
    if (node == nullptr) return;

    preOrder(node->left);
    cout << node->value.word << " " << node->value.frequency << endl;
    preOrder(node->right);
}

void AvlTree::push(WordInfo& info) {
    Item* item = new Item(info);
    insert(item, &root);
}

void AvlTree::showPreOrder() {
    cout << this->length << endl;
    this->preOrder(root);
}
