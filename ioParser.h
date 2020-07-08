
#ifndef IOPARSER_H
#define IOPARSER_H

#include <string>
#include <vector>

using namespace std;

class IOParser {
    public:
        void parseFile(string fileName);
        int getLineCount();
        vector<string> getLines();
        static vector<string> parseCsvLine(string line);
    private:
        vector<string> lines;
        int lineCount;
};

#endif /* processPop_h */