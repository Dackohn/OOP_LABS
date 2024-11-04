#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

class FileReader {
private:
    string filename;

public:
    FileReader(const string& filePath) : filename(filePath) {}

    string readFileContent() {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Failed to open the file: " << filename << endl;
            return "";
        }

        stringstream buffer;
        buffer << file.rdbuf();
        file.close();
        return buffer.str();
    }

    string getFilename() const {
        return filename;
    }
};

class TextData {
private:
    string text;
    int numberOfVowels;
    int numberOfConsonants;
    int numberOfLetters;
    int numberOfSentences;
    string longestWord;

    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    TextData(const string& textContent) : text(textContent), numberOfVowels(0), numberOfConsonants(0),
                                          numberOfLetters(0), numberOfSentences(0) {
        processText();
    }

    void processText() {
        stringstream stream(text);
        string word;
        while (stream >> word) {
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
            for (char ch : word) {
                if (isalpha(ch)) {
                    numberOfLetters++;
                    if (isVowel(ch)) {
                        numberOfVowels++;
                    } else {
                        numberOfConsonants++;
                    }
                }
            }
        }
        for (char ch : text) {
            if (ch == '.' || ch == '?' || ch == '!') {
                numberOfSentences++;
            }
        }
    }

    void printInfo(const string& fileName) const {
        cout << "File Name: " << fileName << endl;
        cout << "Text Content: " << text << endl;
        cout << "Number of Vowels: " << numberOfVowels << endl;
        cout << "Number of Consonants: " << numberOfConsonants << endl;
        cout << "Number of Letters: " << numberOfLetters << endl;
        cout << "Number of Sentences: " << numberOfSentences << endl;
        cout << "Longest Word: " << longestWord << endl;
        cout << "----------------------------------------" << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Please provide at least one .txt file as an argument." << endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        FileReader fileReader(argv[i]);
        string fileContent = fileReader.readFileContent();

        if (!fileContent.empty()) {
            TextData textData(fileContent);
            textData.printInfo(fileReader.getFilename());
        }
    }

    return 0;
}
