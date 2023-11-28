#include <iostream>
#include <unordered_map>
#include <sstream>

// Prints frequencies of 
// individual words in str
void printFrequencies(const std::string& str)
{   
    // declaring map of <string, int> type, 
    // each word is mapped to its frequency
    std::unordered_map<std::string, int> wordFreq;

    // breaking input into word using 
    // string stream
    std::stringstream ss(str);
    
    // To store individual words
    std::string word;

    // now iterating over word, freq pair 
    // and printing them in <, > format
    while (ss >> word) {
        wordFreq[word]++;
    }

    // Printing frequencies
    for (const auto& pair : wordFreq) {
        std::cout << "(" << pair.first << ", " << pair.second << ")\n";
    }
}

// Test code
int main()
{
    std::string str = "do not let trouble trouble you do";
    printFrequencies(str);
    return 0;
}

