#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include "ioParser.h"
#include "population.h"

using namespace std;


void IOParser::parseFile(string fileName) {
    ifstream file(fileName);
    string line;

    if(!file) //Always test the file open.
    {
        cout<<"Error opening output file"<< endl;
        system("pause");
        return;
    }
    while (getline(file, line))
    {
        this->lines.push_back(line);
    }
    this->lineCount = this->lines.size();
}

vector<string> IOParser::getLines() {
    return this->lines;
}

int IOParser::getLineCount() {
    return this->lineCount;
}




vector<string> IOParser::parseCsvLine(string line) {
    vector<string> lineItems;
    string substring;
    stringstream *token_ptr = new stringstream(line);
    while((*token_ptr).good()) {
        getline(*token_ptr, substring, ',');
        lineItems.push_back(substring);
    }
    return lineItems;
}
