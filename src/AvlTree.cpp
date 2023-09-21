#include "AvlTree.hpp"

#include <queue>

#define dbg(x) cout << #x << " = " << x << endl

AvlTree::AvlTree(ofstream& file) : file(file) {
    this->root = nullptr;
    length = 0;
}

AvlTree::~AvlTree() {}

int getHeight(Item *node) {
    if (node == nullptr) return 0;
    return node->height;
}

void rightRotate(Item **y) {
    // Item *x = y->left;
    // Item *T2 = x->right;

    // x->right = y;
    // y->left = T2;

    // y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    // x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    Item *aux;
    aux = (*y)->left;
    (*y)->left = aux->right;
    aux->right = (*y);
    (*y)->height = max(getHeight((*y)->left), getHeight((*y)->right)) + 1;
    aux->height = max(getHeight(aux->left), (*y)->height) + 1;
    (*y) = aux;
}

void leftRotate(Item **x) {
    // Item *y = x->right;
    // Item *T2 = y->left;

    // y->left = x;
    // x->right = T2;

    // x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    // y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    if((*x)->right == nullptr) return;

    Item *aux;
    aux = (*x)->right;
    (*x)->right = aux->left;
    aux->left = (*x);
    (*x)->height = max(getHeight((*x)->left), getHeight((*x)->right)) + 1;
    aux->height = max(getHeight(aux->left), (*x)->height) + 1;
    (*x) = aux;
}

void AvlTree::insert(Item *item, Item **node) {
    if (*node == nullptr) {
        *node = item;
        (*node)->left = nullptr;
        (*node)->right = nullptr;
        return;
    }

    int itemFreq = item->value.frequency;
    int nodeFreq = (*node)->value.frequency;

    if (itemFreq >= nodeFreq)
        insert(item, &(*node)->right);
    else {
        insert(item, &(*node)->left);
    }

    int leftHeight = getHeight((*node)->left);

    int rightHeight = getHeight((*node)->right);

    (*node)->height = max(leftHeight, rightHeight) + 1;

    int balance = leftHeight - rightHeight;

    int leftFreq = 0;
    if ((*node)->left != nullptr) leftFreq = (*node)->left->value.frequency;

    int rightFreq = 0;
    if ((*node)->right != nullptr) leftFreq = (*node)->right->value.frequency;

    if (balance > 1 && itemFreq < leftFreq) {
        rightRotate(&(*node));
    }

    if (balance < -1 && itemFreq > rightFreq) {
        leftRotate(&(*node));
    }

    if (balance > 1 && itemFreq > leftFreq) {
        leftRotate(&((*node)->left));
        rightRotate(&(*node));
    }

    if (balance < -1 && itemFreq < rightFreq) {
        rightRotate(&((*node)->right));
        leftRotate(&(*node));
    }
}

void AvlTree::preOrder(Item *node) {
    if (node == nullptr) return;

    preOrder(node->left);
    file << node->value.word << " " << node->value.frequency << " ";
    preOrder(node->right);
}

void AvlTree::push(WordInfo &info) {
    Item *item = new Item(info);
    insert(item, &root);
}

void AvlTree::showPreOrder() {
    this->preOrder(root);
};
