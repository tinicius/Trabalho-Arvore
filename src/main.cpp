#include <filesystem>
#include <fstream>
#include <queue>

#include "AvlTree.hpp"
#include "BinaryTree.hpp"
#include "HuffmanTree.hpp"
#include "TopKElements.hpp"

using namespace std;

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

void run(int K) {

    double time = 0;

    vector<string> inputWords = getInputWords();

    ofstream file("./output.txt");

    for (auto& text : filesystem::directory_iterator("./textos")) {
        string textPath = text.path().string();

        file << "=============================================================="
                "=================================="
             << endl;

        file << "Texto: " << textPath << endl << endl;

        unordered_map<string, int> freqTable;
        insertOnFreqTable(freqTable, textPath);

        // cout << freqTable.size() << endl;

        for (string& inputWord : inputWords) {
            if (freqTable[inputWord] == 0) continue;

            int aux = freqTable[inputWord];
            freqTable[inputWord] = 0;

            vector<WordInfo> elements = getTopKElements(K, freqTable);

            freqTable[inputWord] = aux;

            clock_t startExe, endExe;
            double execution_time;

            startExe = clock();

            // BinaryTree binaryTree(file);
            AvlTree avlTree(file);

            for (auto e : elements) {
                // binaryTree.push(e);
                avlTree.push(e);
            }

            file << "Palavra: " << inputWord << endl << endl;

            // file << "Huffman: ";
            // createHuffmanTree(elements, file);
            // file << endl;

            // file << "Binária: ";
            // binaryTree.showPreOrder();
            // file << endl;

            file << "AVL: ";
            avlTree.showPreOrder();
            file << endl;

            endExe = clock();
            execution_time = ((double)(endExe - startExe)) / CLOCKS_PER_SEC;

            time+= execution_time * 1000;

            file << endl;
        }
    }

    cout << time << endl;

    file.close();
}

int main() {
    for (int i = 0; i < 5; i += 1) {
        run(1000);
    }

    return 0;
}