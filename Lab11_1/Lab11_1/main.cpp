#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createDataFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "bdeghjklinformaticspquvwxyz";
        file.close();
        cout << "Data file '" << filename << "' created successfully." << endl;
    }
    else {
        cerr << "Error creating file." << endl;
    }
}

void rewriteData(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);
    if (inputFile.is_open() && outputFile.is_open()) {
        string word = "informatics";
        char character;
        while (inputFile.get(character)) {
            if (word.find(character) != string::npos && character != ' ') {
                outputFile << character;
            }
        }
        inputFile.close();
        outputFile.close();
        cout << "Data contained in the word 'informatics' has been successfully rewritten to file '" << outputFilename << "'." << endl;
    }
    else {
        cerr << "Error opening file." << endl;
    }
}

void printFileContents(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        char character;
        cout << "Contents of file '" << filename << "':" << endl;
        while (file.get(character)) {
            cout << character;
        }
        cout << endl;
        file.close();
    }
    else {
        cerr << "Error opening file." << endl;
    }
}

int main() {
    string inputFilename, outputFilename;

    cout << "Enter the name of the data file: ";
    cin >> inputFilename;

    cout << "Enter the name of the file to write data: ";
    cin >> outputFilename;

    createDataFile(inputFilename);
    rewriteData(inputFilename, outputFilename);
    printFileContents(outputFilename);

    return 0;
}
