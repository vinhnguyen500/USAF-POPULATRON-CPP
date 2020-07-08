

#ifndef POPULATION_H
#define POPULATION_H

#include <string>
#include <vector>

using namespace std;

class Population {
    public:
        void addPopulation(int addedPop);
        int getTotalPop();
        int parsePopulationFromRawData(vector<string> input);
        int parsePopulationFromLine(vector<string> lineItems);
        string getFormattedWorldPopulationString();
        Population();
    private:
        int totalPop;

};

#endif /* processPop_h */