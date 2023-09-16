#include "HuffmanTree.hpp"

struct comp {
    constexpr bool operator()(Node* const& a, Node* const& b) const noexcept {
        return a->prob >= b->prob;
    }
};

void codes(Node* node, string code, ofstream& file) {
    if (node->left == nullptr && node->right == nullptr) {
        file << node->info->word << " " << code << " ";
        return;
    }

    string aux = code;
    aux.push_back('1');

    code.push_back('0');

    codes(node->left, code, file);
    codes(node->right, aux, file);
}

void createHuffmanTree(vector<WordInfo>& elements, ofstream& file) {
    priority_queue<Node*, vector<Node*>, comp> pq;

    for (const WordInfo& element : elements) {
        Node* aux = (Node*)malloc(sizeof(Node));

        WordInfo* info = new WordInfo;

        info->frequency = element.frequency;
        info->word = element.word;

        aux->prob = element.frequency;

        aux->info = info;

        aux->left = nullptr;
        aux->right = nullptr;

        pq.push(aux);
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* aux = (Node*)malloc(sizeof(Node));

        aux->prob = left->prob + right->prob;
        aux->left = left;
        aux->right = right;

        pq.push(aux);
    }

    auto a = pq.top();

    codes(a, "", file);
}