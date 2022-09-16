/***************************************************************
  Student Name: Collin Lowing
  File Name: AnalyticalModel.hpp
  Project 2

  Perform calculations using values given by test files
***************************************************************/

#ifndef COP4534_P2_ANALYTICALMODEL_HPP
#define COP4534_P2_ANALYTICALMODEL_HPP


class AnalyticalModel {

public:
    AnalyticalModel(int lambda, int mu, int M);

    double getPercentIdleTime();

    double getAverageTotalPeople();

    double getAverageTimeSpent();

    double getAverageNumberInQueue();

    double getAverageTimeWaitingInQueue();

    double getProportionOfResourcesUsedByArrivals();
};


#endif //COP4534_P2_ANALYTICALMODEL_HPP
