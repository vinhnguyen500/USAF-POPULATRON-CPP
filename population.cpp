#include "population.h"
#include "ioParser.h"


Population::Population(){
    totalPop = 0;
}

void Population::addPopulation(int addedPop){
    this->totalPop += addedPop;
}

int Population::getTotalPop(){
    return this->totalPop;
}

int Population::parsePopulationFromRawData(vector<string> input) {
    //For each line parse the population column and add it to totalPop
    for(int i=1; i<input.size(); i++) {
        vector<string> lineItems = IOParser::parseCsvLine(input[i]);
        this->addPopulation(parsePopulationFromLine(lineItems));
    }
    return this->getTotalPop();
}

int Population::parsePopulationFromLine(vector<string> lineItems) {

    //get the fourth item in the line which has the population
    string populationString = lineItems[4];
    long pop = 0;
    //convert the population value to an integer and return it
    if(populationString.length() > 0) {
        pop = stoi(populationString);
    }
    return pop;
}

string Population::getFormattedWorldPopulationString() {
    string response = "World Population is: ";
    response.append(to_string(this->getTotalPop()));
    response.append(".\n");
    return response;
}