//
//  main.cpp
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;

int processPopulationFile(string fileName) {
    long sum = 0;
    vector<string> lines;
    vector<string> lineItems;
    string line;
    string substring;
    ifstream cityFile(fileName);

    if(!cityFile) //Always test the file open.
    {
        std::cout<<"Error opening output file"<< std::endl;
        system("pause");
        return -1;
    }
    while (std::getline(cityFile, line))
    {
        lines.push_back(line);
    }
    stringstream *token_ptr;
    for(int i=1; i<lines.size(); i++) {
        vector<string> lineItems;
        token_ptr = new stringstream(lines[i]);
        while((*token_ptr).good()) {
            getline(*token_ptr, substring, ',');
            lineItems.push_back(substring);
        }
        substring = lineItems[4];
        long pop = 0;
        if (substring.length() > 0) {
            pop = stoi(substring);
        }
        sum += pop;
        delete token_ptr;
    }
    stringstream ss;
    ss.imbue(std::locale(""));
    ss << std::fixed << sum;
    string num = ss.str();

    cout << "World population is: " << num << "." << endl;
    return 0;
}
