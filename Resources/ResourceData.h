#ifndef RESOURCEDATA_H
#define RESOURCEDATA_H
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const vector<string> splitString(const string& data, const string& delimiter);

const bool checkAnagram(string& leftWord, string& rightWord);

const int* getFrequencies(string& , int numberOfLetters);
const bool isAnagram(const int* letterFrequencies, string& word, int numberOfLetters);
const bool isAnagramWithReuse(const int* letterFrequencies, string& word, int numberOfLetters);
#endif // RESOURCEDATA_H
