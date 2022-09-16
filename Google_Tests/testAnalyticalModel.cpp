/***************************************************************
  Student Name: Collin Lowing
  File Name: testAnalyticalModel.cpp
  Project 2

  tests AnalyticalModel class methods
***************************************************************/

#include "gtest/gtest.h"
#include "../AnalyticalModel.hpp"

TEST(AnalyticalModelTests, getPercentIdleTime) {
    //initialize variables
    int lambda = 2;
    int mu = 3;
    int M = 2;
    double expectedPo = 0.5;
    AnalyticalModel am(lambda, mu, M);
    // action
    double Po = am.getPercentIdleTime();
    // assert
    EXPECT_EQ(Po, expectedPo);
}

TEST(AnalyticalModelTests, getAverageTotalPeople) {
    //initialize variables
    int lambda = 2;
    int mu = 3;
    int M = 2;
    double expectedL = 0.75;
    AnalyticalModel am(lambda, mu, M);
    // action
    double L = am.getAverageTotalPeople();
    // assert
    EXPECT_EQ(L, expectedL);
}

TEST(AnalyticalModelTests, getAverageTimeSpent) {
    //initialize variables
    int lambda = 2;
    int mu = 3;
    int M = 2;
    double expectedW = 0.375;
    AnalyticalModel am(lambda, mu, M);
    // action
    double W = am.getAverageTimeSpent();
    // assert
    EXPECT_EQ(W, expectedW);
}

TEST(AnalyticalModelTests, getAverageNumberInQueue) {
    //initialize variables
    int lambda = 2;
    int mu = 3;
    int M = 2;
    double expectedLq = 0.083;
    AnalyticalModel am(lambda, mu, M);
    // action
    double Lq = am.getAverageNumberInQueue();
    // assert
    EXPECT_EQ(Lq, expectedLq);
}

TEST(AnalyticalModelTests, getAverageTimeWaitingInQueue) {
    //initialize variables
    int lambda = 2;
    int mu = 3;
    int M = 2;
    double expectedWq = 0.0417;
    AnalyticalModel am(lambda, mu, M);
    // action
    double Wq = am.getAverageTimeWaitingInQueue();
    // assert
    EXPECT_EQ(Wq, expectedWq);
}

// proportion of the system's resources which is used by the traffic

TEST(AnalyticalModelTests, getProportionOfResourcesUsedByArrivals) {
    //initialize variables
    int lambda = 6;
    int mu = 3;
    int M = 2;
    double expectedRho = 1;
    AnalyticalModel am(lambda, mu, M);
    // action
    double rho = am.getProportionOfResourcesUsedByArrivals();
    // assert
    EXPECT_EQ(rho, expectedRho);
}