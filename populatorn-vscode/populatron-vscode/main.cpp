
#include <stdio.h>
#include <iostream>
#include "processPop.h"

using namespace std;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cout << "usage: must include file to parse" << endl;
    }
    else {
        processPopulationFile(argv[1]);
    }
    return 0;
}
