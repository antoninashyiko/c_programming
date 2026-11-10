#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    fstream inFile("/Users/chocolatechip/CLionProjects/С++2026_2027/labs/lab14/task2.txt");
    fstream outFile("/Users/chocolatechip/CLionProjects/С++2026_2027/labs/lab14/task2_output.txt");

    if (!inFile || !outFile) {
        cout << "Error opening file" << endl;
        return 1;
    }
    char c;
    string currentWord = "";
    bool flag = false;
    while (inFile.get(c)) {
        if (c == ' ' || c == '\n') {
            if (!currentWord.empty()) {
                if (flag) {
                    currentWord[0] = toupper(currentWord[0]);
                    flag = false;
                }
                if (currentWord == "der" || currentWord == "die" || currentWord == "das") {
                    flag = true;
                    }
                outFile << currentWord;
                currentWord = "";
            }
            outFile << c;

        } else {
            currentWord += c;
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}