#include "ResourceData.h"

const vector<string> splitString(const string& data, const string& delimiter)
{
    string value = data;
    size_t pos = 0;
    string token;
    vector<string> elements;
    while ((pos = value.find(delimiter)) != string::npos) {
            token = value.substr(0, pos);
            elements.push_back(token);
            token = value.erase(0, pos + delimiter.length());
    }
    elements.push_back(token);
    return elements;
}

const int* getFrequencies(string& letters, int numberOfLetters)
{
    int* letterFrequencies = new int[numberOfLetters] {0};
    for (char letter : letters)
    {
        int index = letter - 'a';
        letterFrequencies[index]++;
    }
    return letterFrequencies;
}

const bool isAnagram(const int* letterFrequencies, string& word, int numberOfLetters)
{
    const int* wordFrequencies = getFrequencies(word, numberOfLetters);

    int numberOfMatchedLetters = 0;
    for (int i = 0; i < numberOfLetters; i++ )
    {
        if (letterFrequencies[i] > 0 && letterFrequencies[i] >= wordFrequencies[i])
        {
            numberOfMatchedLetters += wordFrequencies[i];
        }
    }
    delete[] wordFrequencies;
    return numberOfMatchedLetters == word.length() && word.length() >= 3;
}

const bool isAnagramWithReuse(const int* letterFrequencies, string& word, int numberOfLetters)
{
    const int* wordFrequencies = getFrequencies(word, numberOfLetters);

    int numberOfUniqueInWord = 0;
    int numberOfMatchedUniqueInWord = 0;
    for (int i = 0; i < numberOfLetters; i++ )
    {
        if (wordFrequencies[i] > 0)
        {
            numberOfUniqueInWord++;
        }
        if (letterFrequencies[i] > 0 && wordFrequencies[i] > 0)
        {
            numberOfMatchedUniqueInWord++;
        }
    }
    delete[] wordFrequencies;
    return (numberOfMatchedUniqueInWord > 0) && (numberOfMatchedUniqueInWord == numberOfUniqueInWord) && word.length() >= 3;
}
