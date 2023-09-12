#include <filesystem>
#include <queue>

#include "AvlTree.hpp"
#include "BinaryTree.hpp"
#include "HuffmanTree.hpp"
#include "TopKElements.hpp"

using namespace std;

#define K 20

vector<string> getInputWords() {
    ifstream inputFile("./dataset/input.data");

    if (!inputFile) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    }

    vector<string> words;

    string word;

    while (inputFile >> word) words.push_back(word);

    inputFile.close();

    return words;
}

struct myComp {
    constexpr bool operator()(pair<int, HuffmanTree> const& a,
                              pair<int, HuffmanTree> const& b) const noexcept {
        return a.first >= b.first;
    }
};

void codes(Node* node, string code) {
    if (node->left == nullptr && node->right == nullptr) {
        cout<< node->prob << " " << code << " ";
        return;
    }

    string aux = code;
    aux.push_back('1');

    code.push_back('0');

    codes(node->left, code);
    codes(node->right, aux);
}

void huffman() {
    priority_queue<pair<int, HuffmanTree>, vector<pair<int, HuffmanTree>>,
                   myComp>
        pq;

    WordInfo info;
    info.frequency = 1;
    info.word = "";

    pq.push({9, HuffmanTree(&info)});
    pq.push({12, HuffmanTree(&info)});
    pq.push({19, HuffmanTree(&info)});
    pq.push({21, HuffmanTree(&info)});
    pq.push({39, HuffmanTree(&info)});

    while (pq.size() > 1) { 
        HuffmanTree min1 = pq.top().second;
        int p1 = pq.top().first;
        min1.root->prob = p1;
        pq.pop();

        HuffmanTree min2 = pq.top().second;
        int p2 = pq.top().first;
        min2.root->prob = p2;
        pq.pop();

        HuffmanTree aux(nullptr);

        aux.root->left = min1.root;
        aux.root->right = min2.root;

        // aux.insert(&(min1.root), &(min2.root));

        pq.push({p1 + p2, aux});
    }

    auto a = pq.top();

    cout << a.first << endl;

    // bool b = (a.second.root->left == nullptr);

    // cout << b;

    codes(a.second.root, "");
}

int main() {
    huffman();

    return 0;
    cout << endl;

    vector<string> inputWords = getInputWords();

    for (auto& text : filesystem::directory_iterator("./textos")) {
        string textPath = text.path().string();

        cout << "Texto: " << textPath << endl << endl;

        unordered_map<string, int> freqTable;
        insertOnFreqTable(freqTable, textPath);

        for (string& inputWord : inputWords) {
            if (freqTable[inputWord] == 0) continue;

            int aux = freqTable[inputWord];
            freqTable[inputWord] = 0;

            vector<WordInfo> elements = getTopKElements(K, freqTable);

            freqTable[inputWord] = aux;

            BinaryTree binaryTree;
            AvlTree avlTree;

            for (auto e : elements) {
                binaryTree.push(e);
                avlTree.push(e);
            }

            cout << "Palavra: " << inputWord << endl << endl;

            // binaryTree.showPreOrder();
            cout << endl;

            avlTree.showPreOrder();

            cout << endl;
        }
    }

    return 0;
}