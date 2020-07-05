
#include <stdio.h>
#include <streambuf>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "processPop.h" 

using namespace std;

TEST(processPopulation, outputTest) {
    //setup
    string expected = "World population is: 1,347,982,728.\n";


    //redirect standard out
    ostringstream strCout;
    streambuf* oldCout = cout.rdbuf(strCout.rdbuf());

    processPopulationFile("./data/worldcitiespop.csv");

    string actual = strCout.str();
    EXPECT_EQ(actual, expected);

    cout.rdbuf(oldCout);
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
