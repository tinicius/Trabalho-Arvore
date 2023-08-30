#include "TopKElements.hpp"

bool isValidWord(string s) {
    auto expAcents = {"--", "^", "-", " — ", " —", "—", "”", "“", "-”", "——"};

    auto expChar = {'-', '"', '\xE2', '\x80', '\x9D', '\x9C', '\x94'};

    for (auto a : expAcents) {
        if (s.find(a) != s.npos) return false;
    }

    for (auto a : expChar) {
        if (s.find(a) != s.npos) return false;
    }

    return true;
}

bool isValidChar(char c) {
    string acents = "áàâãéèêíïóôõúüçÁÀÂÃÉÈÊÍÏÓÔÕÚÜÇ";

    if (acents.find(c) != acents.npos) return true;

    return iswalnum(c);
}

void readFile(string src, unordered_map<string, int>& freqWordsTable,
              unordered_map<string, int>& stopWordsTable, string& searchWord) {
    ifstream file(src);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << src << "!" << endl;
        exit(1);
    }

    char aux;
    string word;

    while (file) {
        file.get(aux);

        if (isValidChar(aux)) {
            word += tolower(aux);
        } else {
            if (aux == '-' || aux == '/' || aux == '_') continue;

            if (!word.empty() and isValidWord(word) and word != searchWord) {
                if (stopWordsTable.find(word) == stopWordsTable.end()) {
                    freqWordsTable[word]++;
                }
            };

            word = "";
        }
    }

    file.close();
}

void insertElementsOnHeap(Heap& heap, int K,
                          unordered_map<string, int>& freq_table,
                          unordered_map<string, int>& stopWordsTable) {
    int counter = 0;

    for (auto& w : freq_table) {
        if (stopWordsTable[w.first] > 0) continue;

        if (counter < K) {
            heap.push(w);
            counter++;
            continue;
        }

        auto menor = heap.top();

        if (w.second > menor.second) {
            heap.pop();
            heap.push(w);
            counter++;
        }
    }
}

void loadStopWords(unordered_map<string, int>& stopWordsTable) {
    ifstream file("./dataset/stopwords.data");

    if (!file.is_open()) {
        cerr << "Erro ao abrir um dos arquivos de entrada!" << std::endl;
        exit(1);
    }

    string line;

    while (getline(file, line)) {
        stopWordsTable[line]++;
    }

    file.close();
}

vector<WordInfo> getTopKElements(int k, string filePath, string searchWord) {
    unordered_map<string, int> stopWordsTable;
    loadStopWords(stopWordsTable);

    unordered_map<string, int> freqTable;
    readFile(filePath, freqTable, stopWordsTable, searchWord);

    Heap heap;
    insertElementsOnHeap(heap, k, freqTable, stopWordsTable);

    return heap.getElements();
}