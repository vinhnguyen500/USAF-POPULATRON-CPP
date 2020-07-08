//
//  testIt.cpp
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//



#include <stdio.h>
#include <streambuf>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "ioParser.h"
#include "population.h"

using namespace std;


TEST(ioTest, sampleDataFile) {
    //setup
    int expected = 34;
    string input = "./data/test.csv";
    
    IOParser parser;
    parser.parseFile(input);
    EXPECT_EQ(parser.getLineCount(), expected);
}

TEST(ioTest, actualDataFile) {
    //setup
    int expected = 1586978;
    string input = "./data/worldcitiespop.csv";
    
    IOParser parser;
    parser.parseFile(input);
    EXPECT_EQ(parser.getLineCount(), expected);
}

TEST(processPopulation,addSubPopulation){

  //setup
  int input = 5;
  int expected = 5;

  Population testPop;

  testPop.addPopulation(input);

  EXPECT_EQ(testPop.getTotalPop(),expected); 
}

TEST(processPopulation, getTotalPopulation){
  int expected = 10;
  int input = 10;
  Population testPop;
  testPop.addPopulation(input);

  EXPECT_EQ(testPop.getTotalPop(),expected);
}

TEST(processPopulation, addTestPopulation) {
    //setup
    string expected = "World Population is: 34946.\n";
    string input = "./data/test.csv";
    
    IOParser parser;
    parser.parseFile(input);

    Population pop;
    pop.parsePopulationFromRawData(parser.getLines());
    string actual = pop.getFormattedWorldPopulationString();
    EXPECT_EQ(actual, expected);
}

TEST(processPopulation, addActualPopulation) {
    //setup
    string expected = "World Population is: 1347982728.\n";
    string input = "./data/worldcitiespop.csv";
    
    IOParser parser;
    parser.parseFile(input);

    Population pop;
    pop.parsePopulationFromRawData(parser.getLines());
    string actual = pop.getFormattedWorldPopulationString();
    EXPECT_EQ(actual, expected);
}

int main(int argc, char **argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
