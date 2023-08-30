#include "TopKElements.hpp"
#include "BinaryTree.hpp"
using namespace std;

#define K 20

int main() {

    auto elements = getTopKElements(K, "./textos/filosofia.txt", "teoria");

    BinaryTree tree;

    for (auto e : elements) {
        tree.push(e);
    }

    tree.showPreOrder();

    return 0;
}