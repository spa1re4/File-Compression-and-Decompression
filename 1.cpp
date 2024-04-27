#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to perform Run-Length Encoding
void runLengthEncode(const string& input, ofstream& outputFile) {
    int n = input.size();
    for (int i = 0; i < n; i++) {
        int count = 1;
        // Count consecutive occurrences of the current character
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;    
        }
        // Write the character and its count to the output file
        outputFile << input[i] << count;
    }
}

// Function to perform Run-Length Decoding
void runLengthDecode(const string& input, ofstream& outputFile) {
    int n = input.size();
    for (int i = 0; i < n; i += 2) {
        // Get the character
        char character = input[i];
        // Get the count as an integer
        int count = input[i + 1] - '0';
        // Write the character 'count' times to the output file
        for (int j = 0; j < count; j++) {
            outputFile << character;
        }
    }
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "Failed to open the output file." << endl;
        return 1;
    }

    string line;
    int choice;
    cout << "Enter 1 for encoding, 2 for decoding: ";
    cin >> choice;

    // Encoding
    if (choice == 1) {
        while (getline(inputFile, line)) {
            runLengthEncode(line, outputFile);
            outputFile << endl; // Add a newline after each encoded line
        }
    }
    // Decoding
    else if (choice == 2) {
        while (getline(inputFile, line)) {
            runLengthDecode(line, outputFile);
        }
    }
    else {
        cerr << "Invalid choice." << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
