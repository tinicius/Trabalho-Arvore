#include <filesystem>
#include <fstream>
#include <queue>

#include "AvlTree.hpp"
#include "BinaryTree.hpp"
#include "HuffmanTree.hpp"
#include "TopKElements.hpp"

using namespace std;

#define K 20

vector<string> getInputWords() {
    ifstream inputFile("./dataset/input.txt");

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

int main() {
    vector<string> inputWords = getInputWords();

    ofstream file("./output.txt");

    for (auto& text : filesystem::directory_iterator("./textos")) {
        string textPath = text.path().string();

        file << "================================================================================================" << endl;

        file << "Texto: " << textPath << endl << endl;

        unordered_map<string, int> freqTable;
        insertOnFreqTable(freqTable, textPath);

        for (string& inputWord : inputWords) {
            if (freqTable[inputWord] == 0) continue;

            int aux = freqTable[inputWord];
            freqTable[inputWord] = 0;

            vector<WordInfo> elements = getTopKElements(K, freqTable);

            freqTable[inputWord] = aux;

            BinaryTree binaryTree(file);
            AvlTree avlTree(file);

            for (auto e : elements) {
                binaryTree.push(e);
                avlTree.push(e);
            }

            file << "Palavra: " << inputWord << endl << endl;


            file << "Huffman: ";
            createHuffmanTree(elements, file);
            file << endl;

            file << "Binária: ";
            binaryTree.showPreOrder();
            file << endl;

            file << "AVL: ";
            avlTree.showPreOrder();
            file << endl;

            file << endl;
        }
    }

    file.close();

    return 0;
}