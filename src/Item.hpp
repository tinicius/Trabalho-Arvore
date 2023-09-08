#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>

#include "WordInfo.hpp"

using namespace std;

class Item {
   public:
    Item(WordInfo& info);
    virtual ~Item();
    WordInfo value;

    int weight;

    Item* left;
    Item* right;
};

#endif