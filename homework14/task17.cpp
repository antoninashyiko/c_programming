#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream inFile( "/Users/chocolatechip/CLionProjects/С++2026_2027/hw/homework14/input.txt");
    if ( !inFile ) {
        cerr << "Error opening input file" << endl;
        return -1;
    }
    ofstream outFile( "/Users/chocolatechip/CLionProjects/С++2026_2027/hw/homework14/output.txt" );
    if ( !outFile ) {
        cerr << "Error opening output file" << endl;
        return -1;
    }

    string line;
    while ( getline( inFile, line ) ) {
        int count = 1;
        for ( int i = 0; i < (int)line.length()-1; i++ ) {
            if ( line[i] == line[i + 1] ) {
                count++;
            } else {
                if ( count > 1 ) {
                    outFile << line[i] << count;
                }
                else outFile << line[i];
                count = 1;
            }
        }
        if ( count > 1 && !line.empty() ) {
            outFile << line.back() << count;
        }
    }
    inFile.close();
    outFile.close();
}