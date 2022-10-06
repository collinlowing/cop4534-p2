/***************************************************************
  Student Name: Collin Lowing
  File Name: AnalyticalModel.cpp
  Project 2

  Perform calculations using values given by test files
***************************************************************/

#include "AnalyticalModel.hpp"

AnalyticalModel::AnalyticalModel(int lambda, int mu, int M) {
    this->lambda = lambda;
    this->mu = mu;
    this->M = M;
}

double AnalyticalModel::getPercentIdleTime() {
    double result = 0;
    double sum = 0;
    double denominator = 0;

    // calculate summation from 0 to M-1
    for(int i = 0; i <= M - 1; i++)
    {
        double factorialI = getFactorial(i);
        double powerBase = lambda / mu;

        sum += (1 / factorialI) * getPower(powerBase, i);
    }

    // calculate remaining denominator
    denominator = (1 / getFactorial(M))
                  * getPower((lambda / mu), M)
                  * (M * mu) / ((M * mu) - lambda);

    // get final value for Po
    result = 1 / (sum + denominator);

    return result;
}

double AnalyticalModel::getAverageTotalPeople() {
    double result = 0;
    double numerator = 0;
    double denominator = 0;

    numerator = lambda * mu * getPower((lambda / mu), M);
    denominator = getFactorial(M - 1) * getPower((M * mu - lambda), 2);

    result = numerator / denominator;

    result *= getPercentIdleTime();

    result += (lambda / mu);

    return result;
}

double AnalyticalModel::getAverageTimeSpent() {
    return getAverageTotalPeople() / lambda;
}

double AnalyticalModel::getAverageNumberInQueue() {
    return getAverageTotalPeople() - (lambda / mu);
}

double AnalyticalModel::getAverageTimeWaitingInQueue() {
    return getAverageNumberInQueue() / lambda;
}

double AnalyticalModel::getProportionOfResourcesUsedByArrivals() {
    double result = lambda / (mu * M);

    return result;
}

double AnalyticalModel::getFactorial(int number) {
    double factorial = 1;

    for(int i = 1; i <= number; i++) {
        factorial *= i;
    }

    return factorial;
}

double AnalyticalModel::getPower(double base, double exponent) {
    double result = 1;

    while(exponent > 0) {
        result *= base;
        --exponent;
    }

    return result;
}

bool AnalyticalModel::isDoubleEqual(double a, double b) {
    return std::fabs(a - b) < 1E-3;
}