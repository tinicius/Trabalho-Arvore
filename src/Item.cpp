#include "Item.hpp"

Item::Item(WordInfo& info) {
    this->value = info;
    this->weight = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Item::~Item() {
    // delete this->left;
    // delete this->right;
}