//
//  main.cpp
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#include <stdio.h>
#include "processPop.h"
#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    if (argc < 2) {
        cout << "usage: must include file to parse" << endl;
    }
    processPopulationFile(argv[1]);
}
