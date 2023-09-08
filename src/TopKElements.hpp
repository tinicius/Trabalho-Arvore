#ifndef TOP_K_ELEMENTS_HPP
#define TOP_K_ELEMENTS_HPP

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "Heap.hpp"
#include "WordInfo.hpp"

using namespace std;

bool isValidWord(string s);  // Verifica se a palavra não tem algum caracter inválido.
bool isValidChar(char c);  // Verifica se a palavra é alfanumerica, incluindo acentos.

void insertElementsOnHeap(Heap& heap, int K, unordered_map<string, int>& freq_table);

vector<WordInfo> getTopKElements(int k, unordered_map<string, int>& freqTable);
void insertOnFreqTable(unordered_map<string, int>& freqTable, string& filePath);

#endif