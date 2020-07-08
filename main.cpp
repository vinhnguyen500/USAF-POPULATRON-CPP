//
//  main.cpp
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string> 
#include "ioParser.h"
#include "population.h"
using namespace std;


int main(int argc, const char * argv[]) {
    if (argc < 2) {
        cout << "usage: must include file to parse" << endl;
    }
    string filePath = argv[1];
    IOParser parser;
    parser.parseFile(filePath);

    Population pop;
    pop.parsePopulationFromRawData(parser.getLines());
    cout << pop.getFormattedWorldPopulationString() << endl;
}
