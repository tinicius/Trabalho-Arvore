#include <filesystem>

#include "AvlTree.hpp"
#include "BinaryTree.hpp"
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

int main() {
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

            binaryTree.showPreOrder();
            cout << endl;

            avlTree.showPreOrder();

            cout << endl;
        }
    }

    return 0;
}